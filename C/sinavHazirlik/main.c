/*
#include <stdio.h>

int isle(int d[ ],int i);
int main(){
int dizi[ ]={2,4,9,0};
printf("%d",isle(dizi, 3));
}
int isle(int d[],int i)
{
if(i==1 || i==0) return d[i];
return isle(d,i-1)*isle(d,i-2)+i*i;
}
*/

/*
#include <stdio.h>
#define yazdir printf
#define dondur for
int main()
{
int i=1, j=i+2;
dondur(; i<j;)
{
yazdir("%d %d %d\n", i, j, i/j);
++i;
}
return 0;
}
*/
/*
#include <stdio.h>
int main()
{
int a=2;
switch(a? (a*a):(a/a))
{
case 0: printf("%d ",++a*0);
case 1: printf("%d ",1?5:10);
case 2: printf("%d ",++a*2);
case 3: printf("%d ",0?4:8);
case 4: printf("%d ",++a*4);
case 5: printf("%d ",3?6:9);
default: printf("%d ",++a*6);
}
return 0;}
*/
/*
#include <stdio.h>
int main()
{
int a=3;
if(a=2)
printf("atilan gol:%d\n",a);
printf("yenilen gol:%d\n",a);
if(a!=2)
printf("atilan gol:%d\n",a);
printf("yenilen gol:%d\n",a);
return 0;
}
*/
/*
#include <stdio.h>
void isle(int, int*);
void isle2(int*, int);
int main()
{
int a, b;
a=5;
b=7;
isle(a,&b);
printf("%d %d\n", a, b);
isle2(&a,b);
printf("%d %d\n", a, b);
return 0;
}
void isle(int a, int*b)
{
a*=*b*3/2+1;
*b=2;
return;
}
void isle2(int* a, int b)
{
*a=3;
b=*a*2/2*2+3;
return;
}
*/
/*
#include <stdio.h>
int main()
{
int a=5, d=4;
int *b=&a;
int *c;
c=&d;
*c*=2;
*b=*c+2;
printf("%d %d %d %d %d", a,*b,*c,d,a**c+*b*d);
return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    char a[20]="selasmmke";
    char b[20];
    char c[20];
    sscanf(a,"%[^a]a%s",b,c);
    puts(b);
    puts(c);

}


































