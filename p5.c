#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct 
{
    char nume;
    int raza;
    int lungime;
    int latime;
}fig_geom;


//VARIANTA CU UNION (STRUCTURI CU VARIANTE)

// typedef struct 
// {
//     char nume;
//     union 
//     {
//         int raza;
//         struct 
//         {
//             int lungime;
//             int latime;   
//         }dimensiune;
//     }informatie;
// }fig_geom_2;


int main()
{
    fig_geom figura1;
    float perimetru;
    printf("introduceti 'c' pentru cerc, 'p' pentru patrat sau 'd' pentru dreptunghi : ");
    scanf("%c", &figura1.nume);
    //in while se afiseaza de 2 ori cele 2 printf pt ca se retine in memorie tasta, dar si enterul pe care il apesi
    while(figura1.nume != 'c' && figura1.nume != 'p' && figura1.nume != 'd')
    {
        printf("ati tastat alta litera decat cele puse la dispozitie. mai incercati!");
        printf("introduceti 'c' pentru cerc, 'p' pentru patrat sau 'd' pentru dreptunghi : ");
        scanf("%c", &figura1.nume);
    }
    switch(figura1.nume)
    {
        case 'c' :
            printf("introduceti raza cercului : ");
            scanf("%d", &figura1.raza);
            perimetru = (float)(2 * M_PI * figura1.raza);
            printf("perimetru cercului este : %.2f\n", perimetru);
            break;
        case 'p' :
            printf("introduceti lungimea laturii : ");
            scanf("%d", &figura1.lungime);
            perimetru = (int)(4 * figura1.lungime);
            printf("perimetrul patratului este : %d\n", (int)perimetru);
            break;
        case 'd' :
            printf("introduceti lungimea laturii :");
            scanf("%d", &figura1.lungime);
            printf("introduceti latimea laturii : ");
            scanf("%d", &figura1.latime);
            perimetru = (int)(2 * figura1.lungime + 2 * figura1.latime);
            printf("perimetrul dreptunghiului este : %d\n", (int)perimetru);
            break;
        default : break;
    }
    return 0;
}