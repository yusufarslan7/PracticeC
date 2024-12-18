#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>  // sleep fonksiyonu i�in

int main()
{
    const int n = 1000;
    int array[n];

    // Paralel d�ng�de her i� par�ac���n�n bir iterasyonu dinamik �ekilde almas� sa�lan�r.
    #pragma omp parallel for schedule(dynamic, 1)
    for (int i = 0; i < n; ++i) {
        array[i] = i;

        // Her i� par�ac��� k���k bir gecikme ekleyerek paralel �al���rken kar��may� sim�le ediyoruz.
        usleep(1000); // 1 milisaniye gecikme ekler

        // �� par�ac���n�n ��kt�s�
        printf("i: %d, thread: %d\n", array[i], omp_get_thread_num());
    }

    printf("Paralel d�ng� tamamland�.\n");

    return 0;
}
