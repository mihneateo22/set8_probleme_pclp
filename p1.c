#include<stdio.h>
#include<stdlib.h>

typedef struct complex
{
    int real;
    int imaginar;
}nr_complex;

int main()
{
    nr_complex x, y;
    scanf("%d", &x.real);
    scanf("%d", &x.imaginar);
    scanf("%d", &y.real);
    scanf("%d", &y.imaginar);
    int s_real = 0, dif_real, s_im = 0, dif_im;
    s_real = x.real + y.real;
    dif_real = abs(x.real - y.real);
    s_im = x.imaginar + y.imaginar;
    dif_im = abs(x.imaginar - y.imaginar);
    printf("suma celor 2 numere este : %d + %di\n", s_real, s_im);
    printf("diferenta celor 2 numere este : %d + %di\n", dif_real, dif_im);
    return 0;
}