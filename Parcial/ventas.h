#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED


typedef struct
{
    int id;
    int cantidadAfiches;
    int idCliente;
    char nombreArchivo[50];
    int zona;
    int cuitCliente;
    int isEmpty;
    int estado;

}Ventas;

void ven_init_isEmpty(Ventas* pVentas, int limite);
int ven_getEspacioVacio(Ventas* pVentas , int limite);
void ven_altaVentas(Ventas* pVentas,Cliente* pCliente, int limite);
void ven_listarVentas(Ventas* pVentas,int limite);
void ven_modificarVentas(Ventas* pVentas,Cliente* pCliente, int limite);
int ven_validarIDcliente(Cliente* pCliente,int limite,int id);
int ven_validarCuitCliente(Cliente* pCliente,int limite,int cuit);
void ven_cobrarVentas(Ventas* pVentas,Cliente* pCliente,int limite);
#endif // VENTAS_H_INCLUDED
