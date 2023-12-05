#include <stdio.h>
#include <stdlib.h>

int main()
{
    float r=0.0;
    printf("yaricap gir: ");
    scanf("%f",&r);
    for(float y=r;y>=-r;y--){
        for(float x=-r;x<=r;x++){
            if(x*x+y*y<=r*r){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
