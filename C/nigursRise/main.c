#include <stdio.h>
#include <stdlib.h>

int main()
{
    int not,d1=0,d2=0,d3=0,d4=0,d5=0;
    printf("\nnot gir (cikis icin eof): ");
    while((not=getchar())!= 'g'){
        fflush(stdin);
        switch(not){
            case'A':case'a':
                ++d1;
                break;

            case'B':case'b':
                ++d2;
                break;

            case'C':case'c':
                ++d3;
                break;

            case'D':case'd':
                ++d4;
                break;

            case'F':case'f':
                ++d5;
                break;
            case'\n':case' ':
                break;
            default:
                printf("\n\nYanlis karakter girdiniz..\n\n");
                break;

        }
          printf("\nnot gir (cikis icin eof): ");
    }
    printf("A not: %d\nB not: %d\nC not: %d\nD not: %d\nF not: %d\n",d1,d2,d3,d4,d5);
    return 0;
}
