#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "eLetra.h"

eLetra* nuevaLetra(void)
{
    eLetra* returnAux = NULL;
    eLetra* pLetra = malloc(sizeof(eLetra));

    if(pLetra != NULL)
    {
        returnAux = pLetra;
    }

    return returnAux;

}

void printLetra(eLetra* this)
{
   printf("%c %10s %4d %4d\r\n", eLetra_getLetra(this), eLetra_getNombre(this), eLetra_getVocal(this), eLetra_getConsonante(this));
}

void printCantidad(eLetra* this)
{
  printf("%c %4d\r\n", eLetra_getLetra(this), eLetra_getCantidad(this));
}

int esVocalOConsonante(ArrayList* this, int i)
{
    char var = eLetra_getLetra(this->get(this, i));
    int retorno = 0;

    if(var == 'a' || var == 'e' || var == 'i' || var == 'o' || var == 'u')
    {
     retorno = 1;
    }

    return retorno;
}

int contarLetra(ArrayList* this, char letra)
{

   int contador=0;
   int i = 0;
   int tam=this->len(this);


   for(i=0; i < tam; i++)
           {
               if(letra == eLetra_getLetra(this->get(this, i)))
                  {
                      contador++;
                  }
           }

           return contador;
}

ArrayList* crearListaCantidad(ArrayList* this)
{
    ArrayList* listaCantidad = al_newArrayList();
    char caracter = 'a';
    int cantidad = 0;

    while(caracter <= 'z' )
        {
            cantidad = contarLetra(this, caracter);

           if(listaCantidad != NULL)
           {
               eLetra* tmp = nuevaLetra();
               tmp->letra = caracter;//hay que cambiarlo por el setter pero no funciona
               eLetra_setCantidad(tmp, cantidad);
               listaCantidad->add(listaCantidad, tmp);
           }
           caracter++;
        }


    return listaCantidad;
}

int compareLetra(void* letraA , void* letraB)
{


    if(letraA > letraB)
    {
        return 1;
    }
    if(letraA < letraB)
    {
        return -1;
    }
    return 0;


}


ArrayList* crearListaDescendente(ArrayList* this)
{
    ArrayList* listaDescendente = al_newArrayList();
    listaDescendente = al_clone(this);


    listaDescendente->sort(listaDescendente, compareLetra, 0);


    return listaDescendente;


}

int comprobarPalabra(ArrayList* this , int tam)
{
   //char caracter = 'a';
   char letra;
   int contador=0;
   int contadorP=0;
   int j = 0;
   int i = 0;
   int k = 0;
   char ingreso[21];
   int retorno=0;

    printf("Ingrese una palabra de maximo 20 caracteres\n");
    fflush(stdin);
    gets(ingreso);
        while(strlen(ingreso)> 20)
            {
            printf("\nError, reingrese una palabra de maximo 20 caracteres\n");
            fflush(stdin);
            gets(ingreso);
            }
    int tamP = strlen(ingreso);

       while(j < tamP )
        {
           contador = 0;
           contadorP = 0;


           for(k=0; k < tamP; k++)
           {

               if(ingreso[j] == ingreso[k])
                  {
                      contadorP++;
                  }
           }

                //while(caracter <= 'z' )
                {
                   contador = 0;

                   for(i=0; i < tam; i++)
                   {
                       letra = eLetra_getLetra(this->get(this, i));

                       if(letra == ingreso[j])
                          {
                              contador++;
                          }
                   }

                   //printf("Letra %c - Cantidad %d\n", caracter, contador);
                   //caracter++;
                   //printf("contadorP %d contador %d", contadorP, contador);
                   if(contador < contadorP)
                   {
                       printf("Cantidad de letras %c en el ingreso: %d\nCantidad de letras %c en la base: %d\nLetras insuficientes\n", ingreso[j], contadorP, ingreso[j], contador);
                       retorno -1;
                       break;
                   }
                }


           //printf("Letra %c - Cantidad %d\n", ingreso[j], contador);
           j++;
           if(j==tamP)
           {
               printf("Hay suficientes letras para poder escribir su palabra");
               retorno = 1;
           }

        }


        return retorno;

}

char* eLetra_setLetra(eLetra* this, char letra)
{
    //strcpy(this->letra, letra);
     this->letra = letra;
     //printf("%s", letra);
     //printf("%s", this->letra);

}
int eLetra_getLetra(eLetra* this)
{
     //printf("%s", this->letra);
     return this->letra;
}

char* eLetra_setNombre(eLetra* this, char* nombre)
{
     strcpy(this->nombre, nombre);
}
int eLetra_getNombre(eLetra* this)
{
     return this->nombre;
}

int eLetra_setVocal(eLetra* this, int vocal)
{
    this->vocal = vocal;
}
int eLetra_getVocal(eLetra* this)
{
    return this->vocal;
}

int eLetra_setConsonante(eLetra* this, int consonante)
{
    this->consonante = consonante;
}
int eLetra_getConsonante(eLetra* this)
{
    return this->consonante;
}

int eLetra_setCantidad(eLetra* this, int cantidad)
{
    this->cantidad = cantidad;
}
int eLetra_getCantidad(eLetra* this)
{
    return this->cantidad;
}
