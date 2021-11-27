#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "controller.h"
#include <time.h>
#include "inputs.h"
#include <string.h>

float aleatorioFloat(int max, int min, int id);
void* asignador(void* pElement);
int aleatorio(int max, int min, int id);
void* asignador2(void* pElement);
int filterGeneroDrama(void* pElement);


int main()
{
    int option;
    LinkedList* listaPeliculas = ll_newLinkedList();
//    LinkedList* listaDrama = ll_newLinkedList();

  //  controller_loadFromTextInit(listaPeliculas);
    /*listaPeliculas = ll_map(listaPeliculas, asignador);
    controller_ListMovies(listaPeliculas);*/
/*
    listaPeliculas = ll_map(listaPeliculas, asignador2);
    controller_ListMovies(listaPeliculas);*/

    fflush(stdin);

    do
    {

        if(!utn_getNumeroEntero(&option,"\nMenu de acciones\n\n"
                                " 1. Cargar Peliculas de un csv - hecho\n"
                                " 2. Imprimir Lista - hecho\n"
                                " 3. Asignar Rating - hecho\n"
                                " 4. Asignar genero - hecho \n"
                                " 5. Filtrar por genero\n"
                                " 6. Ordenar peliculas\n"
                                " 7. Guardar peliculas - hecho\n"
                                " 8. salir\n"
                                "Seleccione una opcion: ",
                                "\nError opcion invalida. Seleccione una opcion del ",1,8,3))

        switch(option)
            {
                case 1: // csv
                    system("cls");
                    if(controller_loadFromTextInit(listaPeliculas))
                        {
                            printf("\nCarga de datos desde archivo .csv exitosa\n");
                        }
                    else
                        {
                            printf("\nError en la carga de datos desde archivo .csv\n");
                        }
                    break;

                case 2:
                    if(controller_ListMovies(listaPeliculas))
                        {
                            printf("\nCarga de datos desde archivo .bin exitosa\n");
                        }
                    else
                        {
                            printf("\nError en la carga de datos desde archivo .bin\n");
                        }
                    break;
                case 3:
                    listaPeliculas = ll_map(listaPeliculas, asignador);
                    break;
                case 4:
                    listaPeliculas = ll_map(listaPeliculas, asignador2);
                    break;
                case 5:
                    /*LinkedList* listadrama = ll_filter(listaPeliculas, filterGeneroDrama);
                    controller_saveAsText_Init(listadrama);*/
                    //listaDrama = ll_filter(listaPeliculas, filterGeneroDrama);
                    break;

                case 7:
                        controller_saveAsText_Init(listaPeliculas);
                    break;

            }
    }
    while(option != 8);
    return 0;
}


float aleatorioFloat(int max, int min, int id){

        // aleatorios

    float numero;
    srand(id + time(NULL));
    numero = (float) (rand() % (max-min+1) + min)/10;
    return numero;
    // aleatorios
}

int aleatorio(int max, int min, int id){

        // aleatorios

    int porc1;
    srand(id + time(NULL));
    porc1 = rand() % (max-min+1) + min;
    return porc1;
    // aleatorios
}


void* asignador(void* pElement){
    eMovie* aux=NULL;
    float numero;

    if(pElement != NULL){
        aux=(eMovie*) pElement;
        numero = (float)aleatorioFloat(100,1,(aux->id_peli));
        aux->rating = numero;
    }
    return aux;
}

void* asignador2(void* pElement){
    eMovie* aux=NULL;
    int numero;

    if(pElement != NULL){
        aux=(eMovie*) pElement;
        numero = aleatorio(4,1,(aux->id_peli));
        switch(numero){
        case 1:
            strcpy(aux->genero, "drama");
        break;
        case 2:
            strcpy(aux->genero, "comedia");
        break;
        case 3:
            strcpy(aux->genero, "accion");
        break;
        case 4:
            strcpy(aux->genero, "terror");
        break;
        }
        //aux->rating = numero;
    }
    return aux;
}

int filterGeneroDrama(void* pElement){
    int retorno = 0;
    if(!strcmp(((eMovie*) pElement)-> genero, "drama")){
        retorno =1;
    }
    return retorno;
}
