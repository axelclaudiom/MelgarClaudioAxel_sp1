#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"

int parser_MoviesFromText(FILE* pFile , LinkedList* pArrayListMovies)
{
    eMovie *pMovies;
	char auxId[50];
	char auxTitulo[200];
	char auxGenero[50];
	char auxRating[50];

	int todoOk = 0;

	if (pFile != NULL && pArrayListMovies != NULL)
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxTitulo, auxGenero,auxRating); // lectura cabecera
            do
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxTitulo, auxGenero,auxRating);
                pMovies = movie_newParametros(auxId, auxTitulo, auxGenero,auxRating);

                if (pMovies != NULL)
                    {
                        ll_add(pArrayListMovies, pMovies);
                        todoOk = 1;
                    }
            }while(!feof(pFile));
        }

    return todoOk;
}

int parser_MoviesToText(FILE* pFile , LinkedList* pArrayListMovies)
{
	int todoOk = 0;
	eMovie *pMovies;

    int Id;
    char titulo[200];
    char genero[200];
    float rating;
	int tam;


	if (pFile != NULL && pArrayListMovies != NULL)
	{
		tam = ll_len(pArrayListMovies);
		fprintf(pFile, "id_peli,titulo,genero,rating\n");

		for (int i = 0; i < tam; i++)
		{
            pMovies = (eMovie*)ll_get(pArrayListMovies, i);
			if(pMovies != NULL &&
				movie_getId(pMovies, &Id) &&
				movie_getTitulo(pMovies, titulo) &&
				movie_getGenero(pMovies, genero) &&
				movie_getRating(pMovies, &rating))
			{
				fprintf(pFile, "%d,%s,%s,%f\n", Id, titulo, genero, rating);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
