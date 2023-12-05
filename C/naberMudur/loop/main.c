#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("N\t\t10*N\t\t100*N\t\t1000*N\n\n");
    for(int i=1;i<11;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n",i,i*10,i*100,i*1000);
    }
    return 0;
}
