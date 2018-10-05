#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "ventas.h"
#include <stdio_ext.h>
#define LIMITE_CLIENTE 10
#define LIMITE_VENTAS 1000

int main()
{
    Cliente cliente[LIMITE_CLIENTE];
    Ventas  venta[LIMITE_VENTAS];
    int menu;
    char respuesta='n';

    cl_init_isEmpty(cliente,LIMITE_CLIENTE);
    ven_init_isEmpty(venta,LIMITE_VENTAS);
    do
    {
        system("clear");
        printf("\nMenu ");
        printf("\n1-Alta cliente");
        printf("\n2-Modificar cliente");
        printf("\n3-Baja cliente");
        printf("\n4-Vender Afiche");
        printf("\n5-Editar Venta");
        printf("\n6-Salir");

        menu=utn_getInt("\nIngrese opcion: ");

        switch(menu)
        {
            case 1:
                cl_altaCliente(cliente,LIMITE_CLIENTE);
                printf("Desea volver al menu?(s o n)");
                while(scanf("%c",&respuesta)==0 || (respuesta != 's' && respuesta!='n' && respuesta!='S' && respuesta!='N'))
                {
                    printf("Error. Ingrese s o n: ");
                }
                break;
            case 2:
                cl_modificarCliente(cliente,LIMITE_CLIENTE);
                printf("Desea volver al menu?(s o n)");
                while(scanf("%c",&respuesta)==0 || (respuesta != 's' && respuesta!='n' && respuesta!='S' && respuesta!='N'))
                {
                    printf("Error. Ingrese s o n: ");
                }
                break;
            case 3:
                cl_bajaCliente(cliente,LIMITE_CLIENTE);
                printf("Desea volver al menu?(s o n)");
                while(scanf("%c",&respuesta)==0 || (respuesta != 's' && respuesta!='n' && respuesta!='S' && respuesta!='N'))
                {
                    printf("Error. Ingrese s o n: ");
                }
                break;
            case 4:
                ven_altaVentas(venta,cliente,LIMITE_VENTAS);
                printf("Desea volver al menu?(s o n)");
                while(scanf("%c",&respuesta)==0 || (respuesta != 's' && respuesta!='n' && respuesta!='S' && respuesta!='N'))
                {
                    printf("Error. Ingrese s o n: ");
                }
                break;
            case 5:
                ven_modificarVentas(venta,cliente,LIMITE_VENTAS);
                printf("Desea volver al menu?(s o n)");
                while(scanf("%c",&respuesta)==0 || (respuesta != 's' && respuesta!='n' && respuesta!='S' && respuesta!='N'))
                {
                    printf("Error. Ingrese s o n: ");
                }
                break;
            case 6:
                respuesta='n';
                break;

        }
    }while(respuesta!='n');




    return 0;
}
