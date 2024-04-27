#include <stdio.h>
#include <stdlib.h>

int main()
{   int saat=0;
    while(1){
        printf("Calisma saati giriniz(-1 cikis): ");
        scanf("%d",&saat);
        inputClear();
        if(saat<=40 && saat>=0)printf("\nCalisanin maasi: %d.00$\n\n",saat*10);
        else if(saat==-1) break;
        else if(saat<-1){
            printf("Lutfen gecerli saat giriniz..\n\n");
            main();
            break;
        }
        else printf("Calisanin maasi: %d.00$",400+(saat-40)*15);
    }
    return 0;
}

void inputClear(){
    while(getchar() !='\n' && getchar()!= EOF);
}
