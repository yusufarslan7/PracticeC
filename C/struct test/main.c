#include <stdio.h>
#include <stdlib.h>

typedef struct{
char ad[32];
int numara;
}Sins;

void degistir(Sins* abe);

int main()
{
    Sins porno={" Johnny",31};
    degistir(&porno);

    printf("%s %d", porno.ad,porno.numara);

    return 0;
}

void degistir(Sins* abe)
{
    strcpy(abe->ad,"selamm");
    abe->numara=331;
    printf("%s %d ",abe->ad,abe->numara);
}
