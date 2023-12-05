#include <stdio.h>
#include <stdlib.h>
int no=0,lim=0,har=0;
int main()
{   for(int i=0;i<3;i++){
        printf("enter no: ");
        scanf("%d",&no);
        printf("enter lim: ");
        scanf("%d",&lim);
        printf("enter har: ");
        scanf("%d",&har);
        printf("\n\nhesap no: %d\nyeni limit: %d\nlimit durumu: %s\n\n",no,lim/2,(lim/2)-har < 0 ? "limit asildi!" : "limit asilmadi.");


}

    return 0;
}
