#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eLetra.h"


void cargar(ArrayList *list){

    FILE* pFile;
    int tmp;

    tmp = parseLetra(pFile, list);
}

int parseLetra(FILE* pFile, ArrayList* list)
{
    int aux = -1;
    int cont=0;
    int contGral=0;

    pFile = fopen("./datos.csv","r");

    if(pFile != NULL)
    {
    char* letra=(char *)malloc(sizeof(char)*51);
    char* nombre=(char *)malloc(sizeof(char)*51);
    char* vocal=(char *)malloc(sizeof(char)*51);
    char* consonante=(char *)malloc(sizeof(char)*51);

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", letra, nombre, vocal, consonante);

    while(!feof(pFile))
    {
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", letra, nombre, vocal, consonante);
    //printf("%s", letra);
    //printf("ok");
    eLetra *tmp = nuevaLetra();

    if(tmp != NULL)
    {
        if(!isalpha(letra) && strlen(nombre) < 21 && (atoi(vocal) == 0 || atoi(vocal) == 1) && (atoi(consonante) == 0 || atoi(consonante) == 1))
           {
               eLetra_setLetra(tmp, letra[0]);
                //printf("%c", eLetra_getLetra(tmp));
                eLetra_setNombre(tmp, nombre);
                eLetra_setVocal(tmp, atoi(vocal));
                eLetra_setConsonante(tmp, atoi(consonante));
                //printf("%c %10s %4d %4d\r\n", eLetra_getLetra(tmp), eLetra_getNombre(tmp), eLetra_getVocal(tmp), eLetra_getConsonante(tmp));
                list->add(list, tmp);
                cont++;
           }
           else
            {
                printf("El valor numero %d no se pudo parsear, verifique", contGral+1);
            }
            contGral++;
    }

    }

    }
    fclose(pFile);
}


