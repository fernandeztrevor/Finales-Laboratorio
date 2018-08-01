#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Deposito.h"




int main()
{
    ArrayList* list0 = al_newArrayList();
    ArrayList* list1 = al_newArrayList();

    parseDeposito(list0, 0);
    parseDeposito(list1, 1);

    ArrayList* auxList0 = al_clone(list0);
    ArrayList* auxList1 = al_clone(list1);

    int eleccion = 0;
    int dep;
    int prod;
    int result;
    int tam0 = al_len(auxList0);
    int tam1 = al_len(auxList1);

    do{
        printf("1- Listar depositos\n2- Mover Producto\n9- Salir\n");
        scanf("%d", &eleccion);

        switch(eleccion)
        {
    case 1:
                tam0 = al_len(auxList0);
                tam1 = al_len(auxList1);

                printf("Seleccione el deposito que desea listar (0-1):\n");
                scanf("%d", &dep);
                while(dep != 0 && dep != 1)
                {
                    printf("Error, seleccione el deposito que desea listar (0-1):\n");
                    scanf("%d", &dep);
                }

                if(dep == 0)
                {
                    printf("DEPOSITO 0\nProducto Descripcion Cantidad\n");
                    for(int i=0 ; i<tam0; i++)
                    {
                       listarDeposito(auxList0, i) ;
                    }
                }
                if(dep == 1)
                {
                    printf("DEPOSITO 1\nProducto Descripcion Cantidad\n");
                    for(int i=0 ; i<tam1; i++)
                    {
                       listarDeposito(auxList1, i) ;
                    }
                }

                printf("\n");
                system("pause");
                system("cls");

        break;

    case 2:
                tam0 = al_len(auxList0);
                tam1 = al_len(auxList1);

                printf("Seleccione el deposito al que desea acceder (0-1):\n");
                scanf("%d", &dep);
                while(dep != 0 && dep != 1)
                {
                    printf("Error, seleccione el deposito al que desea acceder (0-1):\n");
                    scanf("%d", &dep);
                }
                if(dep == 0)
                {
                    printf("DEPOSITO 0\nProducto Descripcion Cantidad\n");
                    for(int i=0 ; i<tam0; i++)
                    {
                       listarDeposito(auxList0, i) ;
                    }

                    printf("Ingrese el producto que desea mover de deposito\n");
                    scanf("%d", &prod);

                    result = moverProducto(auxList0, auxList1, prod);

                    if(result = 1)
                    {
                        printf("Articulo movido exitosamente\n");
                    }
                    else
                    {
                       printf("No se pudo mover el articulo\n");
                    }

                }
                if(dep == 1)
                {
                    printf("DEPOSITO 1\nProducto Descripcion Cantidad\n");
                    for(int i=0 ; i<tam1; i++)
                    {
                       listarDeposito(auxList1, i) ;
                    }

                    printf("Ingrese el producto que desea mover de deposito\n");
                    scanf("%d", &prod);

                    result = moverProducto(auxList1, auxList0, prod);


                    if(result = 1)
                    {
                        printf("Articulo movido exitosamente\n");
                    }
                    else
                    {
                       printf("No se pudo mover el articulo\n");
                    }
                }



                printf("\n");
                system("pause");
                system("cls");

        break;



        }

        }while(eleccion!=9);

    return 0;
}
