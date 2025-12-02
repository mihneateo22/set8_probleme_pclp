#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char titlu[50];
    unsigned int an;
    struct 
    {
        char nume[20];
        char prenume[20];
        char gen;
    }autor;
}carte;

void citire_struct(unsigned int *n, carte v[]);
void cautare_autor(unsigned int *n, carte v[], char nume_autor[], char prenume_autor[]);
void afisare_info_carte(unsigned int i, carte v[]);

int main()
{
    carte v[10];
    unsigned int n;
    char nume_autor[20], prenume_autor[20];
    citire_struct(&n, v);
    cautare_autor(&n, v, nume_autor, prenume_autor);
    return 0;
}

void citire_struct(unsigned int *n, carte v[])
{
    unsigned int i;
    printf("introduceti numarul de elemnete din tablou : ");
    scanf("%d", n);
    getchar();
    printf("introduceti titlul cartilor : \n");
    for(i = 0; i < *n; i++)
    {
        printf("introduceti titlul cartii %u : ", i + 1);
        fgets(v[i].titlu, 50, stdin);
        v[i].titlu[strcspn(v[i].titlu, "\n")] = '\0';
    }
    printf("introduecti anul publicatie pentru fiecare carte : \n");
    for(i = 0; i < *n; i++)
    {
        printf("anul publicatie cartii %u : ", i + 1);
        scanf("%d", &v[i].an);
    }
    getchar();
    printf("introduceti numele complet al autorului : \n");
    for(i = 0; i < *n; i++)
    {
        printf("nume autor %u : ", i + 1);
        fgets(v[i].autor.nume, 20, stdin);
        v[i].autor.nume[strcspn(v[i].autor.nume, "\n")] = '\0';
        printf("prenume autor %u : ", i + 1);
        fgets(v[i].autor.prenume, 20, stdin);
        v[i].autor.prenume[strcspn(v[i].autor.prenume, "\n")] = '\0';    
    }
    printf("genul abordat : \n");
    for(i = 0; i < *n; i++)
    {
        printf("gen autor %u : ", i + 1);
        scanf("%c", &v[i].autor.gen);
        getchar();
    }
}

void afisare_info_carte(unsigned int i, carte v[])
{
    printf("titlul cartii : ");
    puts(v[i].titlu);
    printf("anul publicatie : %u\n", v[i].an);
}

void cautare_autor(unsigned int *n, carte v[], char nume_autor[], char prenume_autor[])
{
    unsigned int i;
    printf("numele autorului de cautat : ");
    fgets(nume_autor, 20, stdin);
    nume_autor[strcspn(nume_autor, "\n")] = '\0';
    printf("prenumele autorului de cautat : ");
    fgets(prenume_autor, 20, stdin);
    prenume_autor[strcspn(prenume_autor, "\n")] = '\0';
    for(i = 0; i < *n; i++)
    {
        if(strcmp(nume_autor, v[i].autor.nume) == 0 && strcmp(prenume_autor, v[i].autor.prenume) == 0)
            afisare_info_carte(i, v);
    }
}