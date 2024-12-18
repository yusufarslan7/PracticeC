#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>  // sleep fonksiyonu için

int main()
{
    const int n = 1000;
    int array[n];

    // Paralel döngüde her iþ parçacýðýnýn bir iterasyonu dinamik þekilde almasý saðlanýr.
    #pragma omp parallel for schedule(dynamic, 1)
    for (int i = 0; i < n; ++i) {
        array[i] = i;

        // Her iþ parçacýðý küçük bir gecikme ekleyerek paralel çalýþýrken karýþmayý simüle ediyoruz.
        usleep(1000); // 1 milisaniye gecikme ekler

        // Ýþ parçacýðýnýn çýktýsý
        printf("i: %d, thread: %d\n", array[i], omp_get_thread_num());
    }

    printf("Paralel döngü tamamlandý.\n");

    return 0;
}
