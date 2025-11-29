#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int ora;
    int minut;
    int secunda;
}timp;

timp suma_timp(timp x, timp y)
{
    timp rezultat;
    rezultat.secunda = x.secunda + y.secunda;
    rezultat.minut = x.minut + y.minut;
    rezultat.ora = x.ora + y.ora;
    if(rezultat.secunda >= 60)
    {
        rezultat.secunda -= 60;
        rezultat.minut++;
    }
    if(rezultat.minut >= 60)
    {
        rezultat.minut -= 60;
        rezultat.ora++;
    }
    return rezultat;
}

int main()
{
    timp x, y, rezultat;
    printf("timpul 1 este urmatorul : \nore : ");
    scanf("%d", &x.ora);
    printf("\nminute : ");
    scanf("%d", &x.minut);
    printf("\nsecunde : ");
    scanf("%d", &x.secunda);
    printf("\n");
    printf("timpul 2 este urmatorul : \nore : ");
    scanf("%d", &y.ora);
    printf("\nminute : ");
    scanf("%d", &y.minut);
    printf("\nsecunde : ");
    scanf("%d", &y.secunda);
    rezultat = suma_timp(x, y);
    printf("timpul rezultat este : \nore : %d\nminute : %d\nsecunde : %d\n", rezultat.ora, rezultat.minut, rezultat.secunda);
    return 0;
}