#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char firma[50];
    char produs[20];
    int cantitate;
}informatie;

int main()
{
    informatie array[6];
    char product[20];
    unsigned int contor, i, mini = 100000, cnt_maxi, aparitie = 0;
    int maxi = -1;
    printf("introduceti produsul de verificat : ");
    scanf("%s", product);
    getchar();
    printf("introduceti de la tastatura informatiile necesare : \n\n");
    printf("numarul firmelor : ");
    scanf("%u", &contor);
    printf("numele firmelor : ");
    for(i = 0; i < contor; i++)
    {
        scanf("%s", array[i].firma);
        getchar();
    }
    printf("numele produselor : ");
    for(i = 0; i < contor; i++)
    {
        scanf("%s", array[i]. produs);
        getchar();
    }
    printf("cantitatea de produs : ");
    for(i = 0; i < contor; i++)
        scanf("%u", &array[i].cantitate);
    for(i = 0; i < contor; i++)
    {
        if(strcmp(array[i].produs, product) == 0)
        {
            aparitie++;
            if(array[i].cantitate > maxi)
            {
                maxi = array[i].cantitate;
                cnt_maxi = i;
            }
            if(array[i].cantitate < mini)
                mini = array[i].cantitate;
        }
    }
    if(aparitie == 0)
    {
        printf("produsul nu este in nicio firma!\n");
        return 1;
    }
    printf("firma care realizeaza cea mai mare cantitate din produsul %s este %s\n", product, array[cnt_maxi].firma);
    printf("cantitatea totala din produsul %s ce poate fi achizitionata de toate firmele care sunt inscrise in evidenta este %u\n", product, mini);
    return 0;
}