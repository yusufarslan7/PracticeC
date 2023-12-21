#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int a=rand()%90;

    printf("%d",a);
    if(a>=10000)
        return a%10*10000+a/10%10*1000+a/100%10*100+a/1000%10*10+a/10000*1;
    else if(a>=1000)
        return a%10*1000+a/10%10*100+a/100%10*10+a/1000%10*1;
    else if(a>=100)
        return a%10*100+a/10%10*10+a/100%10*1;
    else if(a>=10)
        return a%10*10+a/10%10*1;
    else if(a>=0)
        return a;
}
