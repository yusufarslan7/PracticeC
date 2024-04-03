#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOYUT 30

int main()
{
    char a[BOYUT];
    char b[BOYUT];
    //fgets(a, BOYUT, stdin);
    //fgets(b, BOYUT, stdin);
    //scanf("%3s",a);
    //scanf("%3s",b);
    strcat(a,b);
    puts(a);

    return 0;
}
