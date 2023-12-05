#include<stdio.h>

int main(){
    int n1,n2;
    printf("Karsilastirilacak sayilari\ngiriniz: ");
    scanf("%d%d",&n1,&n2);
    if(n1 == n2){
        printf("%d esittir %d\n",n1,n2);
        main();
    }
    if(n1 < n2)
        printf("%d kucuktur %d\n",n1,n2);
    
    if(n1 > n2)
        printf("%d buyuktur %d\n",n1,n2);
    
    return 0;
}