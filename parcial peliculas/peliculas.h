#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[128];
    char genero[128];
    float rating;
}eMovie;


#endif // PELICULAS_H_INCLUDED


eMovie* movie_new();

eMovie* movie_newParametros(char* id_peliStr,char* tituloStr,char* generoStr, char* ratingStr);

void movie_delete(eMovie* this);

int movie_setId(eMovie* this,int id);
int movie_getId(eMovie* this,int* id);

int movie_setTitulo(eMovie* this,char* titulo);
int movie_getTitulo(eMovie* this,char* titulo);

int movie_setGenero(eMovie* this,char* genero);
int movie_getGenero(eMovie* this,char* genero);

int movie_setRating(eMovie* this,float rating);
int movie_getRating(eMovie* this,float* rating);
