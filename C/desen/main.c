#include <stdio.h>
#include <stdlib.h>

int main(){
    for(int b=1;b<=10;b++){
        for(int i=10-b;i>0;i--){
            printf(" ");
        }
        for(int i=0;i<b;i++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
