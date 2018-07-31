#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "eLetra.h"
#include "Funciones.h"



int main()
{
    ArrayList* list = al_newArrayList();

    cargar(list);
    //printf("ok");
    int tam = list->len();
    int i;
    int correcto;
    int eleccion = 0;
    int cantidad = 0;


    ArrayList* auxList = al_clone(list);
    ArrayList* listaCantidad;
    ArrayList* listaDescendente;
    //ArrayList* CantLetras =

    do{

        printf("1- Listar \n2- Setear vocales y consonantes\n3- Ingresar palabra y buscar letras en la base\n4- Crear y listar lista descendente\n5- Crear y listar lista de cantidad\n9- Salir\n");
        scanf("%d", &eleccion);

        switch(eleccion)
        {
    case 1:
        printf("Letra Nombre Vocal Consonante\n");
        for(i=0; i < tam; i++)
            {
                printLetra((eLetra*)auxList->get(auxList, i));
            }
            printf("\n");
            system("pause");
            system("cls");
        break;
    case 2:
            for(i=0; i < tam; i++)
            {
                if(esVocalOConsonante(auxList, i))
                {
                    //printf("ok");
                    eLetra_setVocal(auxList->get(auxList, i), 1);
                    //auxList->set(eLetra_setVocal(auxList, i))=1;
                }
                else
                {
                   eLetra_setConsonante(auxList->get(auxList, i), 1);
                }

            }
            printf("Seteo completo...");
            printf("\n");
            system("pause");
            system("cls");
        break;
    case 3:
            comprobarPalabra(auxList, tam);

            printf("\n");
            system("pause");
            system("cls");

        break;
    case 4:

        listaDescendente = crearListaDescendente(auxList);
        printf("Letra Nombre Vocal Consonante\n");
        for(i=0; i < tam; i++)
            {
                printLetra((eLetra*)listaDescendente->get(listaDescendente, i));
            }
            printf("\n");
            system("pause");
            system("cls");

        break;

    case 5:

        listaCantidad = crearListaCantidad(auxList);
        printf("Letra Cantidad\n");
        int tamCantidad = listaCantidad->len(listaCantidad);
        for(i=0; i < tamCantidad; i++)
            {
                printCantidad((eLetra*)listaCantidad->get(listaCantidad, i));
            }
            printf("\n");
            system("pause");
            system("cls");

        break;

        }


    }while(eleccion!=9);

    return 0;
}
