#include "pelicula.h"
#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eMovie* movie_new()
{
	eMovie* movie;
	movie = (eMovie*) calloc(sizeof(eMovie),1);

	return movie;
}


eMovie* movie_newParametros(char* idStr,char* nombreStr,char* generoStr,char* ratingStr)
{
	eMovie* movie;
	movie = movie_new();

	int id;
	int rating;

	id = atoi(idStr);
	rating = atoi(ratingStr);


	if( movie!= NULL)
	{
		movie_setId(movie,id);
		movie_setTitulo(movie,nombreStr);
		movie_setGenero(movie,generoStr);
		movie_setRating(movie,rating);
	}
	return movie;
}

int movie_delete(eMovie* this)
{
	int retorno =-1;

	if(this!= NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}


int movie_setId(eMovie* this,int id)
{
	int retorno =-1;
	if(this!= NULL && id>=0)
	{
		this->idPeli = id;
		retorno = 0;
	}
	return retorno;
}

int movie_setTitulo(eMovie* this,char* titulo)
{
	int retorno = -1;
	if(this!= NULL && titulo != NULL)
	{
		strncpy(this->titulo, titulo, sizeof(this->titulo));
	}
	return retorno;
}
int movie_setGenero(eMovie* this,char* genero)
{
	int retorno = -1;
	if(this!= NULL && genero != NULL)
	{
		strncpy(this->genero, genero, sizeof(this->titulo));
	}
	return retorno;
}

int movie_setRating(eMovie* this,int rating)
{
	int retorno =-1;
	if(this!= NULL && rating >= 0)
	{
		this->rating = rating;
	}
	return retorno;
}

/* FUNCIONES GET*/

int movie_getId(eMovie* this,int* id)
{
	int retorno = -1;
	if(this!= NULL && id!= NULL)
	{
		*id = this->idPeli;
		retorno = 0;
	}

	return retorno;
}


int movie_getTitulo(eMovie* this,char* titulo)
{
	int retorno = -1;
	if(this != NULL && titulo != NULL)
	{
		retorno = 0;
		strcpy(titulo, this->titulo);
	}
		return retorno;
}

int movie_getGenero(eMovie* this,char* genero)
{
	int retorno = -1;

	if(this != NULL && genero != NULL)
	{
		retorno = 0;
		strcpy(genero, this->genero);
	}
		return retorno;


}
int movie_getRating(eMovie* this,int* rating)
{
	int retorno =-1;
	if(this!= NULL&& rating!= NULL)
	{
		*rating = this->rating;
		retorno = 0;
	}
	return retorno;


}
