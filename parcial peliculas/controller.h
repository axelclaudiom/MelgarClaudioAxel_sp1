#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

int controller_loadFromTextInit(LinkedList* pArrayListMovies);
int controller_loadFromText(char* path, LinkedList* pArrayListMovies);
int controller_saveAsText_Init(LinkedList* pArrayListMovies);
int controller_saveAsText(char* path , LinkedList* pArrayListMovies);
int controller_ListMovies(LinkedList* pArrayListMovies);
