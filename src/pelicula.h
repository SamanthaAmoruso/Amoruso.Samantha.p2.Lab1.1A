#ifndef MOVIES_H_
#define MOVIES_H_
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int idPeli;
	char titulo[30];
	char genero[30];
	int rating;
	int isEmpty;

}eMovie;


#endif /* MOVIES_H_ */
/**
 * @fn eMovie movie_new*()
 * @brief
 * crea una nueva pelicula
 * @return
 */
eMovie* movie_new();
/**
 * @fn eMovie movie_newParametros*(char*, char*, char*, char*)
 * @brief
 * crea una nueva pelicula y le asigna datos
 * @param idStr
 * @param nombreStr
 * @param generoStr
 * @param duracionStr
 * @return
 */
eMovie* movie_newParametros(char* idStr,char* nombreStr,char* generoStr,char* duracionStr);
/**
 * @fn int movie_delete(eMovie*)
 * @brief
 * elimina una pelicula
 * @param this
 * @return
 */
int movie_delete(eMovie* this);
/**
 * @fn int movie_setId(eMovie*, int)
 * @brief
 * setea el id de la pelicula
 * @param this
 * @param id
 * @return
 */
int movie_setId(eMovie* this,int id);
/**
 * @fn int movie_setTitulo(eMovie*, char*)
 * @brief
 * setea el titulo de la pelicula
 * @param this
 * @param titulo
 * @return
 */
int movie_setTitulo(eMovie* this,char* titulo);
/**
 * @fn int movie_setGenero(eMovie*, char*)
 * @brief
 * setea el genero de la pelicula
 * @param this
 * @param genero
 * @return
 */
int movie_setGenero(eMovie* this,char* genero);
/**
 * @fn int movie_setDuracion(eMovie*, int)
 * @brief
 * setea la duracion de la peicula
 * @param this
 * @param duracion
 * @return
 */
int movie_setRating(eMovie* this,int rating);
/**
 * @fn int movie_getId(eMovie*, int*)
 * @brief
 * consigue el id de la pelicula
 * @param this
 * @param id
 * @return
 */
int movie_getId(eMovie* this,int* id);
/**
 * @fn int movie_getTitulo(eMovie*, char*)
 * @brief
 * consigue el titulo de la pelicula
 * @param this
 * @param titulo
 * @return
 */
int movie_getTitulo(eMovie* this,char* titulo);
/**
 * @fn int movie_getGenero(eMovie*, char*)
 * @brief
 * consigue el genro de la pelicula
 * @param this
 * @param genero
 * @return
 */
int movie_getGenero(eMovie* this,char* genero);
/**
 * @fn int movie_getDuracion(eMovie*, int*)
 * @brief
 * consigue la duracion de la pelicula
 * @param this
 * @param duracion
 * @return
 */
int movie_getRating(eMovie* this,int* rating);
