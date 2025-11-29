#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct
{
    char nume[30];
    int nota1;
    int nota2;
    int nota3;
    float medie;
}student;

int get_grade(student s, int materie)
{
    if (materie == 1) return s.nota1;
    if (materie == 2) return s.nota2;
    return s.nota3;
}

int main()
{
    student array1[6];
    student top[6];
    char subpunct, name[30], temp_char[30];
    int i, j, contor, materie1_2_sau3, maxi = 0, cnt_aparitii = 0, temp;
    bool flag = false;
    //rezolvare subpunct a)
    printf("introduceti numarul de studenti : ");
    scanf("%d", &contor);
    printf("intorduceti numele elevilior : ");
    for(i = 0; i < contor; i++)
    {
        scanf("%s", array1[i].nume);
        getchar();
    }
    printf("introduceti nota1 tuturor elevilor : ");
    for(i = 0; i < contor; i++)
        scanf("%d", &array1[i].nota1);
    printf("introduceti nota2 tuturor elevilor : ");
    for(i = 0; i < contor; i++)
        scanf("%d", &array1[i].nota2);
    printf("introduceti nota3 tuturor elevilor : ");
    for(i = 0; i < contor; i++)
        scanf("%d", &array1[i].nota3);
    printf("\n");
    printf("introduceti subpunctul pe care doresti sa il rezolvi : ");
    getchar();
    scanf("%c", &subpunct);
    printf("\n");
    switch(subpunct)
    {
        case 'b' :
            printf("introduceti numele elevului pe care il cautati : ");
            getchar();
            scanf("%s", name);
            for(i = 0; i < contor; i++)
            {
                if(strcmp(array1[i].nume, name) == 0)
                {
                    printf("informatiile elevului sunt urmatoarele : \n");
                    printf("NUME : %s\n", array1[i].nume);
                    printf("NOTA1 : %d\n", array1[i].nota1);
                    printf("NOTA2 : %d\n", array1[i].nota2);
                    printf("NOTA3 : %d\n", array1[i].nota3);
                    break;
                }
            }
            break;
        case 'c' :
            int k = 0;
            printf("introduceti nateria de comparatie : ");
            scanf("%d", &materie1_2_sau3);
            for(i = 0; i < contor; i++)
            {
                if(materie1_2_sau3 == 1)
                {
                    int nota = get_grade(array1[i], materie1_2_sau3);
                    if(nota > maxi)
                        maxi = nota;
                }
            }
            for(i = 0; i < contor; i++)
            {
                if(get_grade(array1[i], materie1_2_sau3) == maxi)
                    top[k++] = array1[i];
            }
            if(k > 1)
            {
                for(i = 0; i < k - 1; i++)
                {
                    for(j = 0; j < k; j++)
                    {
                        if (strcmp(top[i].nume, top[j].nume) > 0)
                        {
                            student temp = top[i];
                            top[i] = top[j];
                            top[j] = temp;
                        }
                    }
                } 
                printf("elevii cu nota maxima sunt : ");
                for(i = 0; i < k; i++)
                    printf("%s ", top[i].nume);
            } 
            else printf("elevul cu nota maxima este %s\n", top[0].nume);
            break;
        case 'd' :
            for(i = 0; i < contor; i++)
            {
                array1[i].medie = (float)(array1[i].nota1 + array1[i].nota2 + array1[i].nota3) / 3.0;
            }
            for(i = 0; i < contor; i++)
            {
                if(array1[i].medie > maxi)
                {
                    maxi = array1[i].medie;
                    cnt_aparitii++;
                }
            }
            printf("premianti : ");
            for(i = 0; i < contor; i++)
                if(array1[i].medie == maxi)
                    printf("%s ", array1[i].nume);
            printf("\n");
            break;
        case 'e' :
            for(i = 0; i < contor - 1; i++)
                for(j = i + 1; j < contor; j++)
                    if(array1[i].nota2 < array1[j].nota2)
                    {
                        student temp = array1[i];
                        array1[i] = array1[j];
                        array1[j] = temp;
                    }
            printf("Afisare dupa sortare descrescatoare dupa nota2:\n");
            for(i = 0; i < contor; i++)
                printf("%s %d %d %d\n", array1[i].nume, array1[i].nota1, array1[i].nota2,array1[i].nota3);
            break;
        case 'f' :
            for(i = 0; i < contor; i++)
            {
                array1[i].medie = (float)(array1[i].nota1 + array1[i].nota2 + array1[i].nota3) / 3.0;
            }
            printf("nepromovati la cel putin o materie : ");
            for(i = 0; i < contor; i++)
            {
                if(array1[i].medie < 5.00)
                    printf("%s ", array1[i]. nume);
            }
            printf("\n");
            break;
        default :
            printf("mai incearca inca o data. variantele sunt de la b la f : ");
            break;
    }
    return 0;
}