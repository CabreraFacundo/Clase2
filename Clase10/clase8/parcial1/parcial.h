#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED
#include <string.h>

typedef struct
{
    int id;
    int tipo;
    float precio;
    char nombre[50];
    char direccion[60];
    int isEmpty;

}Pantalla;

void bajaDePantalla(Pantalla* pPantalla, int id);
void modificarPantalla(Pantalla* pPantalla, int id);
void init_isEmpty(Pantalla* pPantalla, int limite);
void altaPantalla(Pantalla* pPantalla);
int getEspacioVacio(Pantalla* pPantalla , int limite);
void get_tipo(Pantalla* pPantalla);
void listarPantalla(Pantalla* pPantalla, int limite);
int buscarPantallaPorID(Pantalla* pPantalla, int limite, int id);

#endif // PARCIAL_H_INCLUDED
