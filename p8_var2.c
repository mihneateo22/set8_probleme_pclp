#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct
{
    char nume[50];
    char prenume[50];
    char CNP[15];
}persoana;

//a)

void construire_vector(unsigned int *n, persoana v[]);
void afisare_vector(unsigned int n, persoana v[]);

//b)

void comparare_data_nastere(unsigned int i, unsigned int j, persoana v[]);
void interschimbare(unsigned int i, unsigned int j, persoana v[]);
void selection_sort_data_nastere(unsigned int n, persoana v[]);

//c)
void selection_sort_alfabetic(unsigned int n, persoana v[]);

int main()
{
    unsigned int n;
    persoana v[100];
    construire_vector(&n, v);
    // selection_sort_alfabetic(n, v);
    selection_sort_data_nastere(n, v);
    afisare_vector(n, v);
    return 0;
}

void construire_vector(unsigned int *n, persoana v[])
{
    unsigned int i;
    printf("introduceti numarul de elemente din vector : ");
    scanf("%u", n);
    getchar();
    for(i = 0; i < (*n); i ++)
    {
        printf("elementul %u : \n", i + 1);
        printf("introduceti numele : ");
        fgets(v[i].nume, 50, stdin);
        v[i].nume[strcspn(v[i].nume, "\n")] = '\0';
        printf("introduceti prenumele : ");
        fgets(v[i].prenume, 50, stdin);
        v[i].prenume[strcspn(v[i].prenume, "\n")] = '\0';
        printf("introduceti CNP-ul : ");
        fgets(v[i].CNP, 15, stdin);
        v[i].CNP[strcspn(v[i].CNP, "\n")] = '\0';
    }
}

void afisare_vector(unsigned int n, persoana v[])
{
    unsigned int i;
    printf("\nafisarea finala a vectorului : \n\n");
    for(i = 0; i < n; i++)
    {
        printf("elementul %u :\n", i + 1);
        printf("nume : ");
        puts(v[i].nume);
        printf("prenume : ");
        puts(v[i].prenume);
        printf("CNP : ");
        puts(v[i].CNP);
        printf("\n");
    }
}

void interschimbare(unsigned int i, unsigned int j, persoana v[])
{
    persoana temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void comparare_data_nastere(unsigned int i, unsigned int j, persoana v[])
{
    if((v[i].CNP[0] == '5' || v[i].CNP[0] == '6') && (v[j].CNP[0] == '1' || v[j].CNP[0] == '2'))
        interschimbare(i, j, v);
    else if((v[i].CNP[1] - '0') > (v[j].CNP[1] - '0'))
        interschimbare(i, j, v);
    else if((v[i].CNP[1] - '0') == (v[j].CNP[1] - '0'))
        if((v[i].CNP[2] - '0') > (v[j].CNP[2] - '0'))
            interschimbare(i, j, v);
    else if((v[i].CNP[2] - '0') == (v[j].CNP[2] - '0'))
        if((v[i].CNP[3] - '0') > (v[j].CNP[3] - '0'))
            interschimbare(i, j, v);
    else if((v[i].CNP[3] - '0') == (v[j].CNP[3] - '0'))
        if((v[i].CNP[4] - '0') > (v[j].CNP[4] - '0'))
            interschimbare(i, j, v);
    else if((v[i].CNP[4] - '0') == (v[j].CNP[4] - '0'))
        if((v[i].CNP[5] - '0') > (v[j].CNP[5] - '0'))
            interschimbare(i, j, v);
    else if((v[i].CNP[5] - '0') == (v[j].CNP[5] - '0'))
        if((v[i].CNP[6] - '0') > (v[j].CNP[6] - '0'))
            interschimbare(i, j, v);
}

void selection_sort_data_nastere(unsigned int n, persoana v[])
{
    unsigned int i, j;
    for(i = 0; i < n - 1; i ++)
        for(j = i + 1; j < n; j++)
            comparare_data_nastere(i, j, v);
}

void selection_sort_alfabetic(unsigned int n, persoana v[])
{
    unsigned int i, j;
    persoana temp;
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
        {
            if(strcmp(v[i].nume, v[j].nume) > 0)
                interschimbare(i, j, v);
            else if(strcmp(v[i].nume, v[j].nume) == 0)
            {
                if(strcmp(v[i].prenume, v[j].prenume) > 0)
                    interschimbare(i, j, v);
            }
        }
}