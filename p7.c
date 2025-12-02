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

void citire_struct(unsigned int *n, carte v[]); // subpunct a)
void citire_autor(char nume_autor[], char prenume_autor[]);

//subpunct b)
void cautare_autor(unsigned int *n, carte v[], char nume_autor[], char prenume_autor[]);
void afisare_info_carte(unsigned int i, carte v[]);

//subpunct c)
void max_carti(unsigned int *n, carte v[], char nume_max[], char prenume_max[]);

//subpunct d)
void same_year(unsigned int *n, carte v[]);

//subpunctul e)
void ord_carti(unsigned int *n, carte v[]);
void afisare_info_total(unsigned int *n, carte v[]);

int main()
{
    carte v[10];
    unsigned int n;
    char nume_autor[20], prenume_autor[20], nume_max[20], prenume_max[20];
    citire_struct(&n, v);
    // cautare_autor(&n, v, nume_autor, prenume_autor);
    // max_carti(&n, v, nume_max, prenume_max);
    // same_year(&n, v);
    ord_carti(&n, v);
    afisare_info_total(&n, v);
    return 0;
}

void citire_struct(unsigned int *n, carte v[])
{
    unsigned int i;
    printf("introduceti numarul de elemnete din tablou : ");
    scanf("%d", n);
    getchar();
    printf("introduceti titlul cartilor : \n");
    for(i = 0; i < (*n); i++)
    {
        printf("introduceti titlul cartii %u : ", i + 1);
        fgets(v[i].titlu, 50, stdin);
        v[i].titlu[strcspn(v[i].titlu, "\n")] = '\0';
    }
    printf("introduecti anul publicatie pentru fiecare carte : \n");
    for(i = 0; i < (*n); i++)
    {
        printf("anul publicatie cartii %u : ", i + 1);
        scanf("%d", &v[i].an);
    }
    getchar();
    printf("introduceti numele complet al autorului : \n");
    for(i = 0; i < (*n); i++)
    {
        printf("nume autor %u : ", i + 1);
        fgets(v[i].autor.nume, 20, stdin);
        v[i].autor.nume[strcspn(v[i].autor.nume, "\n")] = '\0';
        printf("prenume autor %u : ", i + 1);
        fgets(v[i].autor.prenume, 20, stdin);
        v[i].autor.prenume[strcspn(v[i].autor.prenume, "\n")] = '\0';    
    }
    printf("genul abordat : \n");
    for(i = 0; i < (*n); i++)
    {
        printf("gen autor %u : ", i + 1);
        scanf("%c", &v[i].autor.gen);
        getchar();
    }
}

void citire_autor(char nume_autor[], char prenume_autor[])
{
    printf("numele autorului de cautat : ");
    fgets(nume_autor, 20, stdin);
    nume_autor[strcspn(nume_autor, "\n")] = '\0';
    printf("prenumele autorului de cautat : ");
    fgets(prenume_autor, 20, stdin);
    prenume_autor[strcspn(prenume_autor, "\n")] = '\0';
}

void afisare_info_carte(unsigned int i, carte v[])
{
    printf("titlul cartii : ");
    puts(v[i].titlu);
    printf("anul publicatie : %u\n", v[i].an);
}

void cautare_autor(unsigned int (*n), carte v[], char nume_autor[], char prenume_autor[])
{
    unsigned int i;
    citire_autor(nume_autor, prenume_autor);
    for(i = 0; i < (*n); i++)
    {
        if(strcmp(nume_autor, v[i].autor.nume) == 0 && strcmp(prenume_autor, v[i].autor.prenume) == 0)
            afisare_info_carte(i, v);
    }
}

void max_carti(unsigned int (*n), carte v[], char nume_max[], char prenume_max[])
{
    unsigned int i, j, cnt, maxi = 0;
    for(i = 0; i < (*n) - 1; i++)
    {
        cnt = 1;
        for(j = i + 1; j < (*n); j++)
        {
            if(strcmp(v[i].autor.nume, v[j].autor.nume) == 0 && strcmp(v[i].autor.prenume, v[j].autor.prenume) == 0)
                cnt++;
        }
        if(cnt > maxi)
        {
            maxi = cnt;
            strcpy(nume_max, v[i].autor.nume);
            strcpy(prenume_max, v[i].autor.prenume);
        }
    }
    printf("AUTORUL CU CELE MAI MULTE CARTI : \n");
    printf("nume : ");
    puts(nume_max);
    printf("prenume : ");
    puts(prenume_max);
}

void same_year(unsigned int *n, carte v[])
{
    unsigned int i, j;
    for(i = 0; i < (*n) - 1; i++)
    {
        for(j = i + 1; j < (*n); j++)
            if((v[i].an == v[j]. an) && (v[i].autor.gen == v[j].autor.gen))
                printf("carti publicate in acelasi an : %u si %u\n", i + 1, j + 1);
    }
}

void afisare_info_total(unsigned int *n, carte v[])
{
    unsigned int i;
    printf("titlul cartilor : \n");
    for(i = 0; i < (*n); i++)
    {
        printf("tilu carte %u : ", i + 1);
        puts(v[i].titlu);
    }
    printf("numele autorilor : \n");
    for(i = 0; i < (*n); i++)
    {
        printf("nume autor %u : ", i + 1);
        puts(v[i].autor.nume);
        printf("prenume autor %u : ", i + 1);
        puts(v[i].autor.prenume);
    }
    printf("anul publicatie : \n");
    for(i = 0; i < (*n); i++)
        printf("an publicatie carte %u : %u\n", i + 1, v[i].an);
}

void ord_carti(unsigned int *n, carte v[])
{
    carte temp;
    unsigned int i, j;
    for(i = 0; i < (*n) - 1; i++)
        for(j = i + 1; j < (*n); j++)
            if(strcmp(v[i].titlu, v[j].titlu) > 0)
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
}