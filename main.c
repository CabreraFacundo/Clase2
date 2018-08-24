#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int numeroMax;
    int numeroMin;
    int i;
    float promedio;
    int acumulador;
    acumulador = 0;

    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero sdsdsdf: ");
        scanf("%d",&numero);
        acumulador = acumulador + numero;

        if(i==0)
        {
            numeroMax=numero;
            numeroMin=numero;
        }
        if(numero < numeroMin)
        {
            numeroMin=numero;
        }
        if(numero > numeroMax)
        {
            numeroMax=numero;
        }
    }

    promedio = (float)acumulador / i;
    printf("El numero maximo es: %d",numeroMax);
    printf("\nEl numero minimo es: %d",numeroMin);
    printf("\nEl promedio es: %f",promedio);

    return 0;
}
