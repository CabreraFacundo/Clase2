#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED

typedef struct
{
    int id;
    char video[50];
    char cuit[50];
    int dias;
    int idPantalla;
    int isEmpty;

}Contrataciones;

void con_modificarContratacion(Contrataciones* pContratacion, Pantalla* pPantalla, int limiteC, int limiteP);
void con_mostrarDatosPantalla(Contrataciones* pContratacion, Pantalla* pPantalla, int limiteC, int limiteP,char* auxCuit);
int con_getEspacioVacio(Contrataciones* pContratacion , int limite);
void con_init_isEmpty(Contrataciones* pContratacion, int limite);
void alta_contrataciones(Contrataciones* pContratacion,Pantalla* pPantalla, int limiteP,int limiteC);
#endif // CONTRATACIONES_H_INCLUDED
