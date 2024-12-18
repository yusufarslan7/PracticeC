#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int npoints;   // Toplam nokta sayýsý
double *x;     // Noktalarý tutacak dinamik dizi

// Diziyi baþlatan fonksiyon
void initialize() {
    for (int i = 0; i < npoints; i++) {
        x[i] = i * 1.0; // Örnek olarak diziyi 0.0, 1.0, 2.0, ... þeklinde dolduruyoruz
    }
}

// Alt diziyi hesaplayan fonksiyon
void compute_subdomain(double *x, int iam, int mypoints) {
    int start = iam * mypoints;          // Her iþ parçacýðýnýn iþlem yapmaya baþlayacaðý indeks
    int end = start + mypoints;          // Her iþ parçacýðýnýn iþlem yapacaðý son indeks
    printf("%d %d\n",start,end);
    // Ýþlem (her bir alt diziyi 2 ile çarpma)
    for (int i = start; i < end; i++) {
        x[i] *= 2.0; // Örnek iþlem: Her elemaný 2 ile çarp
    }
}

int main() {
    printf("Toplam nokta sayýsýný girin: ");
    scanf("%d", &npoints);

    // Dinamik bellek tahsisi
    x = (double *)malloc(npoints * sizeof(double));
    if (x == NULL) {
        printf("Bellek tahsisi baþarýsýz.\n");
        return -1;
    }

    initialize(); // Diziyi baþlat

    // Paralel bölge
    #pragma omp parallel shared(x, npoints)
    {
        int np = omp_get_num_threads(); // Toplam iþ parçacýðý sayýsý
        int iam = omp_get_thread_num(); // Mevcut iþ parçacýðýnýn kimliði
        int mypoints = npoints / np;   // Her iþ parçacýðýnýn eleman sayýsý

        // Alt diziyi iþleme
        compute_subdomain(x, iam, mypoints);

        // Eðer `npoints % np` sýfýr deðilse, kalan noktalar bir iþ parçacýðý tarafýndan iþlenmeli
        if (iam == 0 && npoints % np != 0) {
            for (int i = np * mypoints; i < npoints; i++) {
                x[i] *= 2.0; // Kalan elemanlarý iþleme
            }
        }
    }

    // Sonuçlarý yazdýr
    printf("Sonuçlar:\n");
    for (int i = 0; i < npoints; i+=100) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }

    // Belleði serbest býrak
    free(x);

    return 0;
}
