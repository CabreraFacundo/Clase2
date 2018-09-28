#include <stdio_ext.h>
#include <stdlib.h>
#include "parcial.h"
#include "utn.h"
#include <string.h>
#include "contrataciones.h"
#define LIMITEP 2
#define LIMITEC 2

static int generarId(void)
{
    static int id = 0;
    id++;
    return id;
}

void con_init_isEmpty(Contrataciones* pContratacion, int limite)
{
    int i=0;

    if(pContratacion!= NULL && i<limite)
    {
        for(i=0; i<limite; i++)
        {
            pContratacion[i].isEmpty = 1;
        }
    }
}


void alta_contrataciones(Contrataciones* pContratacion,Pantalla* pPantalla, int limiteP,int limiteC)
{
    int id;
    int index;

    index = con_getEspacioVacio(pContratacion,limiteC);

    listarPantalla(pPantalla,limiteP);
    id = getInt("\nIngrese el ID de la pantalla donde se quiera publicar: ");

    pContratacion[index].id = generarId();
    pContratacion[index].idPantalla = id;
    pContratacion[index].dias = getInt("\nIngrese la cantidad de dias: ");
    getString("\nIngrese el video: ", pContratacion[index].video);
    getString("\nIngrese el cuit: ", pContratacion[index].cuit);
}

int con_getEspacioVacio(Contrataciones* pContratacion , int limite)
{
    int i;
    int index;

    for(i=0;i<limite;i++)
    {
        if(pContratacion[i].isEmpty==1)
        {
            index = i;
        }
    }

    return index;
}

void con_modificarContratacion(Contrataciones* pContratacion, Pantalla* pPantalla, int limiteC, int limiteP)
{
    int idPan;
    int i;
    char auxCuit[50];

    con_mostrarDatosPantalla(pContratacion,pPantalla,limiteC,limiteP,auxCuit);

    __fpurge(stdin);
    idPan = getInt("Ingrese el ID de pantalla: ");

    for(i=0;i<limiteC;i++)
    {
        if(strcmp(pContratacion[i].cuit,auxCuit) == 0 && pContratacion[i].idPantalla == idPan)
        {
            pContratacion[i].dias = getInt("Ingrese la cantidad de dias: ");
        }
    }
}

void con_mostrarDatosPantalla(Contrataciones* pContratacion, Pantalla* pPantalla, int limiteC, int limiteP,char* auxCuit)
{
    int i;

    __fpurge(stdin);
    getString("Igrese el cuit: ",auxCuit);

    for(i=0;i<limiteC;i++)
    {
        if(strcmp(auxCuit,pContratacion[i].cuit) == 0)
        {
            listarPantalla(pPantalla,limiteP);
        }
    }

}

void con_cancelarContratacion(Contrataciones* pContratacion, Pantalla* pPantalla, int limiteC, int limiteP)
{
    char auxCuit[50];
    int idPan;
    int i;

    con_mostrarDatosPantalla(pContratacion,pPantalla,limiteC,limiteP,auxCuit);
    idPan = getInt("Ingrese el ID de pantalla que quiera cancelar: ");

    for(i=0;i<limiteC;i++)
    {
        if(strcmp(pContratacion[i].cuit,auxCuit) == 0 && pContratacion[i].idPantalla == idPan)
        {
            pPantalla[i].isEmpty = 1;
        }
    }
}


void con_consultFacturacion(Contrataciones* pContratacion, Pantalla* pPantalla, int limiteC, int limiteP)
{
    int i;
    float precio;
    char auxCuit[50];
    int idPan;
    int pos;

    getString("Igrese el cuit: ",auxCuit);

    for(i=0;i<limiteC;i++)
    {
        if(strcmp(pContratacion[i].cuit,auxCuit) == 0 )
        {
            idPan = pContratacion[i].idPantalla;

            pos = buscarPantallaPorID(pPantalla,limiteP,idPan);

            precio = pPantalla[pos].precio * pContratacion[i].dias;
            printf("%f",precio);
        }

    }

}


