#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int npoints;   // Toplam nokta say�s�
double *x;     // Noktalar� tutacak dinamik dizi

// Diziyi ba�latan fonksiyon
void initialize() {
    for (int i = 0; i < npoints; i++) {
        x[i] = i * 1.0; // �rnek olarak diziyi 0.0, 1.0, 2.0, ... �eklinde dolduruyoruz
    }
}

// Alt diziyi hesaplayan fonksiyon
void compute_subdomain(double *x, int iam, int mypoints) {
    int start = iam * mypoints;          // Her i� par�ac���n�n i�lem yapmaya ba�layaca�� indeks
    int end = start + mypoints;          // Her i� par�ac���n�n i�lem yapaca�� son indeks
    printf("%d %d\n",start,end);
    // ��lem (her bir alt diziyi 2 ile �arpma)
    for (int i = start; i < end; i++) {
        x[i] *= 2.0; // �rnek i�lem: Her eleman� 2 ile �arp
    }
}

int main() {
    printf("Toplam nokta say�s�n� girin: ");
    scanf("%d", &npoints);

    // Dinamik bellek tahsisi
    x = (double *)malloc(npoints * sizeof(double));
    if (x == NULL) {
        printf("Bellek tahsisi ba�ar�s�z.\n");
        return -1;
    }

    initialize(); // Diziyi ba�lat

    // Paralel b�lge
    #pragma omp parallel shared(x, npoints)
    {
        int np = omp_get_num_threads(); // Toplam i� par�ac��� say�s�
        int iam = omp_get_thread_num(); // Mevcut i� par�ac���n�n kimli�i
        int mypoints = npoints / np;   // Her i� par�ac���n�n eleman say�s�

        // Alt diziyi i�leme
        compute_subdomain(x, iam, mypoints);

        // E�er `npoints % np` s�f�r de�ilse, kalan noktalar bir i� par�ac��� taraf�ndan i�lenmeli
        if (iam == 0 && npoints % np != 0) {
            for (int i = np * mypoints; i < npoints; i++) {
                x[i] *= 2.0; // Kalan elemanlar� i�leme
            }
        }
    }

    // Sonu�lar� yazd�r
    printf("Sonu�lar:\n");
    for (int i = 0; i < npoints; i+=100) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }

    // Belle�i serbest b�rak
    free(x);

    return 0;
}
