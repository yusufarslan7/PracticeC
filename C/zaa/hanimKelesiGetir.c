#include<stdio.h>

int main(){
    int n1;
    printf("Sayi giriniz: ");
    scanf("%d",&n1);
    if (n1 != 7){
        printf("Loaded number is not 7.\n\n");
    }
    else{
        printf("Loaded number is indeed 7\n\n");
    }
    printf("Bu, bir C programidir.\n\n");
    printf("Bu, bir C\nprogramidir.\n\n");
    printf("Bu,\tbir\tC\tprogramidir.");
    return 0;
}