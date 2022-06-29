#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "controller.h"
#include "LinkedList.h"
//#include "parser.h"
#include "pelicula.h"
//#include "informes.h"
#include <time.h>


int menu()
{
	int opcion;
	printf(" \n---Menu---\n");
	printf("1. Cargar archivo\n");
	printf("2. Imprimir lista\n");
	printf("3. Asignar genero\n");
	printf("4. Filtrar por genero\n");
	printf("5. Ordenar peliculas\n");
	printf("6. Guardar peliculas\n");
	printf("7. Salir\n");

	printf("Ingrese opcion:\n");
	scanf("%d", &opcion);
	return opcion;
}



int controller_loadFromText(char* path , LinkedList* pListaMovies)
{
	FILE* pArchivo;
	int retorno = -1;

	if(path != NULL && pListaMovies!= NULL)
	{
		pArchivo = fopen(path,"r");
		if(pArchivo == NULL)
		{
			printf("Error al abrir el archivo\n");
		}
		else
		{
			retorno = 0;
			printf("Se ingresó al archivo exitosamente");
			//parser_MovieFromText(pArchivo, pListaMovies);
			fclose(pArchivo);

		}
	}

return retorno;
}

int controller_saveAsText(char* path , LinkedList* pListaMovies)
{
	FILE* pArchivo;
	int cantidad;
	int i;
	eMovie* pelicula;
	int retorno = -1;

	cantidad = ll_len(pListaMovies);

	pArchivo = fopen(path,"w");

	if(cantidad >0)
	{
		fprintf(pArchivo, "id_peli,titulo,genero,rating\n");

		for(i=0;i<cantidad;i++)
		{
			pelicula = ll_get(pListaMovies,i);
			fprintf(pArchivo, "%d,%s,%s,%d\n", pelicula->idPeli,pelicula->titulo,pelicula->genero,pelicula->rating);
			retorno = 0;;
		}
	}

	fclose(pArchivo);
    return retorno;
}



int controller_ListMovies(LinkedList* pListaMovies)
{
	int i;
	int retorno = -1;
	int cantidad;
	cantidad = ll_len(pListaMovies);
	eMovie* lista;
	if(pListaMovies != NULL && cantidad >0)
	{
		printf("ID              TITULO                 GENERO            RATING\n");

		for(i=0;i<cantidad;i++)
		{
			lista = (eMovie*) ll_get(pListaMovies,i);
			printf("%10d\t %20s\t %12s\t %10d\t\n", lista->idPeli,lista->titulo,lista->genero,lista->rating);
			retorno = 0;

		}
	}

    return retorno;
}

int asignarGenero(LinkedList* this, int(*pFunc) (void*))
{
	int retorno =-1;

	LinkedList* newList;

	if(this!= NULL && pFunc != NULL)
	{
		for(int i =0;i<ll_len(this);i++)
		{
			newList = ll_map(this,asignarAleatorios);
			if(newList)
			{
				retorno = 0;

			}
		}
		controller_ListMovies(newList);
	}
return retorno;
}

int asignarAleatorios(void* elemento)
{
	int retorno = -1;
	eMovie* pelicula;
	pelicula = (eMovie*) elemento;
	if(elemento != NULL)
	{
		pelicula = (int) (rand() % (100 - 10 + 1) + 1)/10;
		retorno = 0;

	}
	return retorno;

}

int filtroTipoDrama(void* elemento)
{

	int todoOk = 0;
	eMovie* peli;
	peli = (eMovie*)elemento;
	char genero[20];
	movie_getGenero(peli,genero);

	if(strcmp(genero,"Drama") == 0){
		todoOk = 1;
	}
	return todoOk;
}

int archivoDrama(LinkedList* lista){

    int todoOk = 0;
    LinkedList* lista2 = ll_newLinkedList();

    lista2 = ll_filter(lista,filtroTipoDrama);

    if(controller_saveAsText("generoDrama.csv",lista2)){
        todoOk = 1;
        printf("El archivo fue generado exitosamente\n");

    }

        return todoOk;
}
int filtroTipoComedy(void* elemento)
{

	int todoOk = 0;
	eMovie* peli;
	peli = (eMovie*)elemento;
	char genero[20];
	movie_getGenero(peli,genero);

	if(strcmp(genero,"Comedy") == 0){
		todoOk = 1;
	}
	return todoOk;
}

int archivoComedy(LinkedList* lista){

    int todoOk = 0;
    LinkedList* lista2 = ll_newLinkedList();

    lista2 = ll_filter(lista,filtroTipoComedy);

    if(controller_saveAsText("generoComedy.csv",lista2)){
        todoOk = 1;
        printf("El archivo fue generado exitosamente\n");

    }

        return todoOk;
}

int filtroTipoHorror(void* elemento)
{

	int todoOk = 0;
	eMovie* peli;
	peli = (eMovie*)elemento;
	char genero[20];
	movie_getGenero(peli,genero);

	if(strcmp(genero,"Horror") == 0){
		todoOk = 1;

	}
	return todoOk;
}

int archivoHorror(LinkedList* lista){

    int todoOk = 0;
    LinkedList* lista2 = ll_newLinkedList();

    lista2 = ll_filter(lista,filtroTipoHorror);

    if(controller_saveAsText("generoHorror.csv",lista2)){
        todoOk = 1;
        printf("El archivo fue generado exitosamente\n");

    }

        return todoOk;
}

int filtroTipoAction(void* elemento)
{

	int todoOk = 0;
	eMovie* peli;
	peli = (eMovie*)elemento;
	char genero[20];
	movie_getGenero(peli,genero);

	if(strcmp(genero,"Action") == 0){
		todoOk = 1;
	}
	return todoOk;
}

int archivoAction(LinkedList* lista){

    int todoOk = 0;
    LinkedList* lista2 = ll_newLinkedList();

    lista2 = ll_filter(lista,filtroTipoAction);

    if(controller_saveAsText("generoAction.csv",lista2)){
        todoOk = 1;
        printf("El archivo fue generado exitosamente\n");

    }

        return todoOk;
}

int archivoPelisOrdenadas(LinkedList* lista)
{
	int todoOk = 0;
	LinkedList* lista2 = ll_newLinkedList();

	lista2= lista;

	if(controller_saveAsText("movies_ordenadas.csv",lista2))
	{
		todoOk = 1;
		printf("El archivo fue generado exitosamente\n");

	}

		return todoOk;
}
