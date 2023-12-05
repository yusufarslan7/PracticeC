#include<stdio.h>

int main(){
    float r,pe,ar;
    /*printf("*********                   ***                    *                    *\n");
    printf("*       *                 *     *                 ***                  * *\n");
    printf("*       *                *       *               *****                *   *\n");
    printf("*       *                *       *                 *                 *     *\n");
    printf("*       *                 *     *                  *                  *   *\n");
    printf("*       *                   * *                    *                   * *\n");
    printf("*********                   * *                    *                    *\n");
    return 0;*/
    printf("yaricap gir: ");
    scanf("%f",&r);
    pe = r*2*3.14159;
    ar = r*r*3.14159;
    printf("cap: %f\ncevre: %f\nalan: %f\n",r*2,pe,ar);
    return 0;
}