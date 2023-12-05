#include<stdio.h>

int main(){
    int n1,n2,n3,re;
    printf("3 sayi giriniz: ");
    scanf("%d%d%d",&n1,&n2,&n3);
    re = n1*n2*n3;
    printf("Sonuc = %d",re);
    return 0;
    /*printf("%d ve %d nin carpimi %d dir.\n", 3, 5,3*5);
    return 0;*/
}