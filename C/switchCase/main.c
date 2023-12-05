#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int i=0;
    while(1){

        int j=i%2;
        switch (j) {
        case 0:
            printf("cift\n");
            break;
        case 1:
            printf("tek\n");
            break;
        }
        i++;
        Sleep(1000);
    }
    return 0;
}
