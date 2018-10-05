#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    int cuit;
    int id;
    int isEmpty;

}Cliente;

void cl_init_isEmpty(Cliente* pCliente, int limite);
int cl_getEspacioVacio(Cliente* pCliente , int limite);
void cl_altaCliente(Cliente* pCliente, int limite);
void cl_modificarCliente(Cliente* pCliente, int limite);
void cl_bajaCliente(Cliente* pCliente, int limite);


#endif // CLIENTE_H_INCLUDED
