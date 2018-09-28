#include <stdio.h>
#include <stdlib.h>
#include "parcial.h"
#include "utn.h"
#include "contrataciones.h"
#define LIMITEP 2
#define LIMITEC 2

int main()
{
    Pantalla pantallas[LIMITEP];
    Contrataciones contratacion[LIMITEC];


    init_isEmpty(pantallas,LIMITEP);
    con_init_isEmpty(contratacion,LIMITEC);
    altaPantalla(pantallas);
    alta_contrataciones(contratacion,pantallas,LIMITEP,LIMITEC);
    con_modificarContratacion(contratacion,pantallas,LIMITEC,LIMITEP);

    return 0;
}
