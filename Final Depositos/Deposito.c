#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Deposito.h"



int parseDeposito(ArrayList* this, int dep)
{
    int aux = -1;
    FILE* pFile;


    if(dep == 0)
    {
       pFile = fopen("./dep0.csv","r");
    }
    if(dep == 1)
    {
      pFile = fopen("./dep1.csv","r");
    }


    if(pFile != NULL)
    {
    char* producto=(char *)malloc(sizeof(char)*51);
    char* descripcion=(char *)malloc(sizeof(char)*51);
    char* cantidad=(char *)malloc(sizeof(char)*51);

    fscanf(pFile,"%[^,],%[^,],%[^\n]\n", producto, descripcion, cantidad);

    while(!feof(pFile))
    {
    fscanf(pFile,"%[^,],%[^,],%[^\n]\n", producto, descripcion, cantidad);

    deposito* tmp = malloc(sizeof(deposito));

    if(tmp != NULL)
    {
    deposito_setProducto(tmp, atoi(producto));
    deposito_setDescripcion(tmp, descripcion);
    deposito_setCantidad(tmp, atoi(cantidad));
    }

    this->add(this, tmp);

    }

    }
    fclose(pFile);
}

/*
deposito* nuevoProducto(void)
{
    deposito* returnAux = NULL;
    deposito* pProducto = malloc(sizeof(deposito));

    if(pProducto != NULL)
    {
        returnAux = pProducto;
    }

    return returnAux;

}*/

int moverProducto(ArrayList* origen, ArrayList* destino, int producto)
{
    int retorno = -1;

    int tam = al_len(origen);

    for(int i=0; i < tam; i++)
    {
        if(producto == deposito_getProducto(origen->get(origen, i)))
        {
            //deposito* tmp = malloc(sizeof(deposito));

            //tmp=origen->get(origen, i);
            destino->add(destino, origen->get(origen, i));

            origen->remove(origen, i);

            retorno = 1;
            break;
        }
    }

    return retorno;
}

void listarDeposito(ArrayList* this, int i)
{
    printf("%4d %10s %4d\n", deposito_getProducto(this->get(this, i)), deposito_getDescripcion(this->get(this, i)), deposito_getCantidad(this->get(this, i)) );
}

int deposito_setProducto(deposito* this, int producto)
{
    this->producto = producto;
}
int deposito_getProducto(deposito* this)
{
    return this->producto;
}

int deposito_setDescripcion(deposito* this, char* descripcion)
{
    strcpy(this->descripcion, descripcion);
}
int deposito_getDescripcion(deposito* this)
{
    return this->descripcion;
}

int deposito_setCantidad(deposito* this, int cantidad)
{
    this->cantidad = cantidad;
}
int deposito_getCantidad(deposito* this)
{
    return this->cantidad;
}
