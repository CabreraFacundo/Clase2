#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "ventas.h"
#include <stdio_ext.h>
static int generarId(void);



static int generarId(void)
{
    static int id = 0;
    id++;
    return id;
}


void ven_init_isEmpty(Ventas* pVentas, int limite)
{
    int i=0;

    if(pVentas!= NULL && i<limite)
    {
        for(i=0; i<limite; i++)
        {
            pVentas[i].isEmpty = 1;
        }
    }
}

int ven_getEspacioVacio(Ventas* pVentas, int limite)
{
    int i;
    int index;

    for(i=0; i<limite; i++)
    {
        if(pVentas[i].isEmpty==1)
        {
            index = i;
        }
    }

    return index;
}


void ven_altaVentas(Ventas* pVentas,Cliente* pCliente, int limite)
{
    int index;
    int menuZona;

    __fpurge(stdin);
    index = ven_getEspacioVacio(pVentas,limite);

    pVentas[index].id = generarId();
    do
    {
        pVentas[index].idCliente = utn_getInt("\nIngrese un id de cliente valido: ");
    }while(ven_validarIDcliente(pCliente,limite,pVentas[index].idCliente)==0);

    __fpurge(stdin);
    do
    {
        pVentas[index].cuitCliente = utn_getInt("Ingrese un cuit de cliente valido: ");
    }while(ven_validarCuitCliente(pCliente,limite,pVentas[index].cuitCliente)==0);

    __fpurge(stdin);
    pVentas[index].cantidadAfiches = utn_getInt("Ingrese la cantidad de afiches: ");

    __fpurge(stdin);
    utn_getString("Ingrese el nombre del archivo(maximo 50 letras): ",pVentas[index].nombreArchivo,50);

    __fpurge(stdin);
    printf("\n1)CABA");
    printf("\n2)ZONA SUR");
    printf("\n3)ZONA OESTE");
    menuZona=utn_getInt("\nIngrese la zona: ");
    switch(menuZona)
    {
    case 1:
        pVentas[index].zona = 1;
        break;
    case 2:
        pVentas[index].zona = 2;
        break;
    case 3:
        pVentas[index].zona = 3;
        break;
    }

    pVentas[index].isEmpty = 0;
    pVentas[index].estado = 1;

}

void ven_modificarVentas(Ventas* pVentas,Cliente* pCliente, int limite)
{
    int id;
    int menuZona;
    int i;

    ven_listarVentas(pVentas,limite);
    id = utn_getInt("\nIngrese el ID que desea modificar: ");

    for(i=0;i<limite;i++)
    {
        if(pVentas[i].id==id)
        {

            do
            {
                pVentas[i].idCliente = utn_getInt("\nIngrese un id de cliente valido: ");
            }while(ven_validarIDcliente(pCliente,limite,pVentas[i].idCliente)==0);

            do
            {
                pVentas[i].cuitCliente = utn_getInt("Ingrese un cuit de cliente valido: ");
            }while(ven_validarCuitCliente(pCliente,limite,pVentas[i].cuitCliente)==0);

            __fpurge(stdin);
            pVentas[i].cantidadAfiches = utn_getInt("\nIngrese la cantidad de afiches: ");

            __fpurge(stdin);
            utn_getString("\nIngrese el nombre del archivo(maximo 50 letras): ",pVentas[i].nombreArchivo,50);

            __fpurge(stdin);
            printf("\n1)CABA");
            printf("\n2)ZONA SUR");
            printf("\n3)ZONA OESTE");
            menuZona=utn_getInt("\nIngrese la zona: ");
            switch(menuZona)
            {
            case 1:
                pVentas[i].zona = 1;
                break;
            case 2:
                pVentas[i].zona = 2;
                break;
            case 3:
                pVentas[i].zona = 3;
                break;
            }
            break;
        }
    }
}

void ven_listarVentas(Ventas* pVentas,int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        if(pVentas[i].isEmpty==0)
        {
            printf("\n-----------------------------------------");
            printf("\nNombre archivo: %s",pVentas[i].nombreArchivo);
            printf("\nCantidad afiches: %d",pVentas[i].cantidadAfiches);
            printf("\nID de cliente: %d",pVentas[i].idCliente);

            switch(pVentas[i].zona)
            {
                case 1:
                    printf("\nZona: CABA");
                    break;
                case 2:
                    printf("\nZona: ZONA SUR");
                    break;
                case 3:
                    printf("\nZona: ZONA OESTE");
                    break;
            }

            printf("\nCuit cliente: %d",pVentas[i].cuitCliente);
            printf("\nID de venta: %d",pVentas[i].id);

            switch(pVentas[i].estado)
            {
                case 1:
                    printf("\nEstado: A cobrar");
                    break;
                case 2:
                    printf("\nEstado: No cobrar");
            }
        }
    }

}

int ven_validarIDcliente(Cliente* pCliente,int limite,int id)
{
    int i;
    int ret;

    for(i=0;i<limite;i++)
    {
        ret = 0;
        if(pCliente[i].id == id)
        {
            ret = 1;
            break;
        }
    }

    return ret;
}

int ven_validarCuitCliente(Cliente* pCliente,int limite,int cuit)
{
    int i;
    int ret;

    for(i=0;i<limite;i++)
    {
        ret = 0;
        if(pCliente[i].cuit == cuit)
        {
            ret = 1;
            break;
        }
    }

    return ret;
}

void ven_cobrarVentas(Ventas* pVentas,Cliente* pCliente,int limite)
{
    int i;
    int id;
    int j;

    ven_listarVentas(pVentas,limite);
    id = utn_getInt("Ingrese el ID de venta: ");

    for(i=0;i<limite;i++)
    {
        if(pVentas[i].id == id)
        {
            for(j=0;j<limite;j++)
            {
                if(pVentas[i].idCliente == pCliente[j].id)
                {
                    printf("\nNombre: %s",pCliente[j].nombre);
                    printf("\nApellido: %s",pCliente[j].apellido);
                    printf("\nCuit: %d",pCliente[j].cuit);
                    printf("\nID: %d",pCliente[j].id);
                    break;
                }
            }
            printf("Cambiar de estado?");
        }
    }

}
