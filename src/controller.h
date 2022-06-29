#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"


#endif /* CONTROLLER_H_ */

int menu();
int controller_loadFromText(char* path , LinkedList* pListaMovies);
int controller_saveAsText(char* path , LinkedList* pListaMovies);
int controller_ListMovies(LinkedList* pListaMovies);
int asignarGenero(LinkedList* this, int(*pFunc) (void*));
int asignarAleatorios(void* elemento);

int filtroTipoDrama(void* elemento);
int archivoDrama(LinkedList* lista);

int filtroTipoComedy(void* elemento);
int archivoComedy(LinkedList* lista);


int filtroTipoHorror(void* elemento);
int archivoHorror(LinkedList* lista);


int filtroTipoAction(void* elemento);
int archivoAction(LinkedList* lista);

int archivoPelisOrdenadas(LinkedList* lista);
