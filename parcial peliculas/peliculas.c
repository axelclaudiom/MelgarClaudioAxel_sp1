#include "peliculas.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

eMovie* movie_new()
{
    eMovie* movie_new;
    movie_new = (eMovie*) malloc(sizeof(eMovie));

    if (movie_new != NULL)
    {
        movie_new->id_peli = 0;
        strcpy(movie_new->titulo, " ");
        strcpy(movie_new->genero, " ");
        movie_new->rating = 0.0;
    }

    return movie_new;
}


eMovie* movie_newParametros(char* id_peliStr,char* tituloStr,char* generoStr, char* ratingStr){

eMovie* pMovie;
    int auxId;
    float auxRating;



    if (id_peliStr != NULL && tituloStr != NULL && generoStr != NULL && ratingStr != NULL)
    {
        pMovie = movie_new();
        auxId = atoi(id_peliStr);
        auxRating = atof(ratingStr);

        if ((pMovie != NULL) &&
                (!(movie_setTitulo(pMovie,tituloStr) &&
                   movie_setGenero(pMovie,generoStr) &&
                   movie_setId(pMovie,auxId) &&
                   movie_setRating(pMovie,auxRating))))
        {
            movie_delete(pMovie);
            pMovie = NULL;
        }
    }
    return pMovie;

}


void movie_delete(eMovie* this){
    if(this != NULL)
    {
        free(this);
    }
}


int movie_setId(eMovie* this,int id){

    int todoOk = 0;
    if( this != NULL && id >0)
    {
        this->id_peli = id;
        todoOk = 1;
    }
    return todoOk;

}

int movie_getId(eMovie* this,int* id){
    int todoOk = 0;
    if( this != NULL && id!= NULL)
    {
        *id = this->id_peli;
        todoOk = 1;
    }
    return todoOk;
}

int movie_setTitulo(eMovie* this,char* titulo){
    int todoOk = 0;
    if (this != NULL && titulo != NULL)
    {
        strlwr(titulo);
        titulo[0] = toupper(titulo[0]);
        strcpy(this->titulo, titulo);
        todoOk = 1;
    }
    return todoOk;
}

int movie_getTitulo(eMovie* this,char* titulo){
    int todoOk = 0;
    if (this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        todoOk = 1;
    }
    return todoOk;
}

int movie_setGenero(eMovie* this,char* genero){
    int todoOk = 0;
    if (this != NULL && genero != NULL)
    {
        strlwr(genero);
        genero[0] = toupper(genero[0]);
        strcpy(this->genero, genero);
        todoOk = 1;
    }
    return todoOk;
}

int movie_getGenero(eMovie* this,char* genero){
    int todoOk = 0;
    if (this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        todoOk = 1;
    }
    return todoOk;
}

int movie_setRating(eMovie* this,float rating){
    int todoOk = 0;
    if( this != NULL && rating >= 0)
    {
        this->rating = rating;
        todoOk = 1;
    }
    return todoOk;
}

int movie_getRating(eMovie* this,float* rating){
    int todoOk = 0;
    if( this != NULL && rating != NULL)
    {
        *rating = this->rating;
        todoOk = 1;
    }
    return todoOk;
}
