#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct
{
    char titlu[50];
    unsigned int an_aparitie;
    struct 
    {
        char nume[20];
        char prenume[20];
        char gen_abordat;
    }autor;
    
}carte;

//a)
void construire_vector(unsigned int *n, carte v[]);

//b
void gasire_carte_dupa_autor(unsigned int n, carte v[], char nume_cautat[20], char prenume_cautat[20]);
void afisare_info_carte(unsigned int i, carte v[]);

//c)
void autor_max(unsigned int n, carte v[], char nume_max[], char prenume_max[]);

//d)
void an_gen(unsigned int n, carte v[], unsigned int an_cautat, char gen_cautat);

//e)
void ordonare_cresc_titlu(unsigned int n, carte v[]);
void afisare_info_total(unsigned int n, carte v[]);

int main()
{
    char nume_cautat[20], prenume_cautat[20], nume_max[20], prenume_max[20], gen_cautat;
    carte v[10];
    unsigned int n, an_cautat;
    construire_vector(&n, v);
    // gasire_carte_dupa_autor(n, v, nume_cautat, prenume_cautat);
    // autor_max(n, v, nume_max, prenume_max);
    // an_gen(n, v, an_cautat, gen_cautat);
    ordonare_cresc_titlu(n, v);
    afisare_info_total(n, v);
    return 0;
}

void construire_vector(unsigned int *n, carte v[])
{
    unsigned int i;
    printf("introduceti : \n");
    printf("numarul de elemente din tablou : ");
    scanf("%u", n);
    getchar();
    for(i = 0; i < (*n); i++)
    {
        printf("titlul cartii %u : ", i + 1);
        fgets(v[i].titlu, 50, stdin);
        v[i].titlu[strcspn(v[i].titlu, "\n")] = '\0';
        printf("anul aparitiei cartii %u : ", i + 1);
        scanf("%u", &v[i].an_aparitie);
        getchar();
        printf("numele autorului cartii %u : ", i + 1);
        fgets(v[i].autor.nume, 20, stdin);
        v[i].autor.nume[strcspn(v[i].autor.nume, "\n")] = '\0';
        printf("prenumele autorului cartii %u : ", i + 1);
        fgets(v[i].autor.prenume, 20, stdin);
        v[i].autor.prenume[strcspn(v[i].autor.prenume, "\n")] = '\0';
        printf("genul abordat al cartii %u : ", i + 1);
        scanf("%c", &v[i].autor.gen_abordat);
        getchar();
    }
}

void gasire_carte_dupa_autor(unsigned int n, carte v[], char nume_cautat[20], char prenume_cautat[20])
{
    unsigned int i, cnt = 0;
    printf("introdu numele de cautat : ");
    fgets(nume_cautat, 20, stdin);
    nume_cautat[strcspn(nume_cautat, "\n")] = '\0';
    printf("introdu prenumele de cautat : ");
    fgets(prenume_cautat, 20, stdin);
    prenume_cautat[strcspn(prenume_cautat, "\n")] = '\0';
    for(i = 0; i < n; i++)
    {
        if(strcmp(v[i].autor.nume, nume_cautat) == 0 && strcmp(v[i].autor.prenume, prenume_cautat) == 0)
        {
            cnt++;
            afisare_info_carte(i, v);
        }
    }
    if(cnt == 0)
        printf("nu exista acest autor in baza noastra de date\n");
}

void afisare_info_carte(unsigned int i, carte v[])
{
    printf("carte %u : \n", i + 1);
    printf("anul publicatiei : %u\n", v[i].an_aparitie);
    printf("titlu : ");
    puts(v[i].titlu);
    printf("gen abordat : %c\n", v[i].autor.gen_abordat);
}

void autor_max(unsigned int n, carte v[], char nume_max[], char prenume_max[])
{
    unsigned int i, j, cnt, maxi = 0;
    for(i = 0; i < n - 1; i++)
    {
        cnt = 1;
        for(j = i + 1; j < n; j++)
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
    printf("autorul care figureaza in evidenta cu cel mai mare numar de carti este : ");
    printf("%s %s", nume_max, prenume_max);
    printf("\n");
}

void an_gen(unsigned int n, carte v[], unsigned int an_cautat, char gen_cautat)
{
    unsigned int i, j, cnt = 0;
    printf("introdu anul de cautat : ");
    scanf("%u", &an_cautat);
    getchar();
    printf("introdu genul de cautat : ");
    scanf("%c", &gen_cautat);
    printf("cartile pubicate in acelasi an si care abordeaza acelasi gen sunt : ");
    for(i = 0; i < n; i++)
    {
        if(v[i].autor.gen_abordat == gen_cautat && v[i].an_aparitie == an_cautat)
        {
            cnt++;
            printf("'%s'  ", v[i].titlu);
        }
    }
    if(cnt == 0)
        printf("nu exista carti cu aceste specificatii in baza noastra de date");
    printf("\n");
}

void ordonare_cresc_titlu(unsigned int n, carte v[])
{
    unsigned int i, j;
    carte temp;
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(strcmp(v[i].titlu, v[j].titlu) > 0)
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
}

void afisare_info_total(unsigned int n, carte v[])
{
    unsigned int i;
    printf("titlul cartilor : \n");
    for(i = 0; i < n; i++)
    {
        printf("tilu carte %u : ", i + 1);
        puts(v[i].titlu);
    }
    printf("numele autorilor : \n");
    for(i = 0; i < n; i++)
    {
        printf("nume autor %u : ", i + 1);
        puts(v[i].autor.nume);
        printf("prenume autor %u : ", i + 1);
        puts(v[i].autor.prenume);
    }
    printf("anul publicatiei : \n");
    for(i = 0; i < n; i++)
        printf("an publicatie carte %u : %u\n", i + 1, v[i].an_aparitie);
}