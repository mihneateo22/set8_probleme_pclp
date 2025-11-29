#include<stdio.h>

typedef struct
{
    int ora;
    int minut;
    int secunda;
}timp;

typedef struct
{
    int zi;
    int luna;
    int an;
    timp moment;
}data;

int main()
{
    data x;
    printf("valorile variabile de tip 'struct data' sunt : \n");
    scanf("%d", &x.moment.ora);
    printf("ora din 'struct timp' : ");
    printf("%d\n", x.moment.ora);
    //etc... la fel si pt x.moment.minut, x.moment.secunda
    //pentru celelalte se face doar cu x.zi, x.luna, x.an
    return 0;
}