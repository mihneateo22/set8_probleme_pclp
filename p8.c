#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct 
{
    char nume[20];
    char prenume[20];
    char CNP[20];
}persoana;

void afisare_total(unsigned int *n, persoana v[]);

//subpunct a)
void citire_struct(unsigned int *n, persoana v[]);

//subpunct b)
void sort_descresc_DN(unsigned int *n, persoana v[]);
void generare_data_nastere(unsigned int *an, unsigned int *luna, unsigned int *zi, persoana v[], unsigned int i);

//subpunct c)
void sort_catalog(unsigned int *n, persoana v[]);

int main()
{
    unsigned int n;
    persoana v[10];
    citire_struct(&n, v);
    // sort_catalog(&n, v);
    sort_descresc_DN(&n, v);
    afisare_total(&n, v);
    return 0;
}

void afisare_total(unsigned int *n, persoana v[])
{
    unsigned int i;
    printf("numele si prenumele persoanelor : \n");
    for(i = 0; i < (*n); i++)
    {
        printf("nume persoana %u : ", i + 1);
        puts(v[i].nume);
        printf("prenume persoana %u : ", i + 1);
        puts(v[i].prenume);
    }
    printf("CNP persoane : \n");
    for(i = 0; i < (*n); i++)
    {
        printf("CNP persoana %u : ", i + 1);
        puts(v[i].CNP);
    }
}

void citire_struct(unsigned int *n, persoana v[])
{
    unsigned int i;
    printf("introduceti numarul de elemente : ");
    scanf("%u", n);
    getchar();
    printf("numele si prenumele persoanelor : \n");
    for(i = 0; i < (*n); i++)
    {
        printf("nume persoana %u : ", i + 1);
        fgets(v[i].nume, 20, stdin);
        v[i].nume[strcspn(v[i].nume, "\n")] = '\0';
        printf("prenume persoana %u : ", i + 1);
        fgets(v[i].prenume, 20, stdin);
        v[i].prenume[strcspn(v[i].prenume, "\n")] = '\0';
    }
    printf("CNP persoane : \n");
    for(i = 0; i < (*n); i++)
    {
        printf("CNP persoana %u : ", i + 1);
        fgets(v[i].CNP, 20, stdin);
        v[i].CNP[strcspn(v[i].CNP, "\n")] = '\0';
    }
}

void generare_data_nastere(unsigned int *an, unsigned int *luna, unsigned int *zi, persoana v[], unsigned int i)
{
    (*an) = (*luna) = (*zi) = 0;
    if(v[i].CNP[0] == '5' || v[i].CNP[0] == '6')
    {
        //generare an
        (*an) += 2000;
        (*an) += (v[i].CNP[1] - '0') * 10 + (v[i].CNP[2] - '0'); 
        //generare luna
        (*luna) += (v[i].CNP[3] - '0') * 10 + (v[i].CNP[4] - '0');
        //generare zi
        (*zi) = (v[i].CNP[5] - '0') * 10 + (v[i].CNP[6] - '0'); 
    }
    else if(v[i].CNP[0] == '1' || v[i].CNP[0] == '2')
    {
        //generare an
        (*an) += 1900;
        (*an) += (v[i].CNP[1] - '0') * 10 + (v[i].CNP[2] - '0'); 
        //generare luna
        (*luna) += (v[i].CNP[3] - '0') * 10 + (v[i].CNP[4] - '0');
        //generare zi
        (*zi) = (v[i].CNP[5] - '0') * 10 + (v[i].CNP[6] - '0'); 
    }
}

void sort_descresc_DN(unsigned int *n, persoana v[])
{
    unsigned int i, j, an_i, luna_i, zi_i, an_j, luna_j, zi_j;
    persoana temp;
    for(i = 0; i < (*n) - 1; i++)
    {
        for(j = i + 1; j < (*n); j++)
        {
            generare_data_nastere(&an_i, &luna_i, &zi_i, v, i);
            generare_data_nastere(&an_j, &luna_j, &zi_j, v, j);
            if((an_i) > (an_j))
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
            else if((an_i) == (an_j))
            {
                if((luna_i) > (luna_j))
                {
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
                else if((luna_i) == (luna_j))
                {
                    if((zi_i) > (zi_j))
                    {
                        temp = v[i];
                        v[i] = v[j];
                        v[j] = temp;
                    }
                }
            }
        }
    }
}

void sort_catalog(unsigned int *n, persoana v[])
{
    unsigned int i, j;
    persoana temp;
    for(i = 0; i < (*n) - 1; i++)
        for(j = i + 1; j < (*n); j++)
            if(strcmp(v[i].nume, v[j].nume) > 0)
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
            else if(strcmp(v[i].nume, v[j].nume) == 0)
            {
                if(strcmp(v[i].prenume, v[j].prenume) > 0)
                {
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
}