#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "inputs.h"
#include "parser.h"
#include "controller.h"

int controller_loadFromTextInit(LinkedList* pArrayListMovies)
{
    int todoOk = 0;
    char confirmacionString[2];
    char confirmacionChar;
    char path[20];
    FILE* f = NULL;
    int tam;

    utn_getDescripcion(path,20, "\nIngrese el path (+ extension .csv): \n","Error. Path invalido.\n",3);

    f = fopen(path, "r");
    if( f == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }
    else
    {
        tam = ll_len(pArrayListMovies) > 0;
        if(tam >0)
        {
            utn_getChar(confirmacionString,2,
                        "\nYa hay datos cargados en el listado, si confirmas seran sobreescribidos. Confirma [s-n] ?: ",
                        "\nError, ingrese S para confirmar, N para cancelar.", 3);

            confirmacionChar = confirmacionString[0];
            confirmacionChar = toupper(confirmacionChar);
        }
    }

    if(f != NULL && (confirmacionChar == 'S' ||  ll_len(pArrayListMovies) == 0))
    {
        ll_clear(pArrayListMovies);
        controller_loadFromText(path, pArrayListMovies);
        todoOk = 1;
    }
    return todoOk;
}


int controller_loadFromText(char* path, LinkedList* pArrayListMovies)
{
    int todoOk = 0;
    FILE* pFile;
    pFile = fopen(path, "r");

    if (pFile != NULL && pArrayListMovies!= NULL)
    {
        parser_MoviesFromText(pFile, pArrayListMovies);
        fclose(pFile);
        todoOk = 1;
    }
    return todoOk;
}


int controller_saveAsText_Init(LinkedList* pArrayListMovies)
{
    int todoOk = 0;
    char confirmacionString[2];
    char confirmacionChar;
    char path[20];
    FILE* f = NULL;

    utn_getDescripcion(path,20, "\nIngrese el path (+ extension .csv): \n","Error. Path invalido.\n",3);
    f = fopen(path, "r");
    if( f != NULL)
        {
            utn_getChar(confirmacionString,2,
                        "\nYa exite ese path, de confirmar va a perder los datos Confirma [s-n]?: ",
                        "\nError, ingrese S para confirmar, N para cancelar.", 3);
            confirmacionChar = confirmacionString[0];
            confirmacionChar = toupper(confirmacionChar);
        }

    if( confirmacionChar == 'S' || f == NULL)
        {
            controller_saveAsText(path, pArrayListMovies);
            todoOk = 1;
        }
    return todoOk;
}




int controller_saveAsText(char* path , LinkedList* pArrayListMovies)
{
	int todoOk = 0;
	FILE *pFile;
	if (path != NULL && pArrayListMovies != NULL)
	{
		pFile = fopen(path, "w");

		if (pFile != NULL)
		{
			parser_MoviesToText(pFile, pArrayListMovies);
			fclose(pFile);
			todoOk = 1;
		}
	}
	return todoOk;
}

int controller_ListMovies(LinkedList* pArrayListMovies)
{
    int todoOk = 0;
    int tam;
    eMovie *pMovies;
    int id;
    char titulo[128];
    char genero[128];
    float rating;

    if(pArrayListMovies == NULL)
    {
        printf("\nNo hay empleados para listar.\n");
    }
    else
    {
        tam = ll_len(pArrayListMovies);
        printf("\n\n           ***Listado de Peliculas***       \n\n");
        printf(" ID    Titulo     Genero        Rating   \n");

        for(int i=0; i<tam; i++)
        {
            pMovies = ll_get(pArrayListMovies, i);
            movie_getId(pMovies, &id);
            movie_getTitulo(pMovies, titulo);
            movie_getGenero(pMovies, genero);
            movie_getRating(pMovies, &rating);
            printf(" %-5d %-25s        %-25s      %f \n", id, titulo, genero,rating);
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}
