//============================================================================
// Name        : Samantha.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "Linkedlist.h"
#include "pelicula.h"
#include "parser.h"
#include "infomes.h"

int main()
{
	setbuf(stdout,NULL);
	fflush(stdin);

	char seguir = 's';
	int carga = 0;
	char nombreArchivo[30];

	LinkedList* listaMovies = ll_newLinkedList();

	do{

			switch(menu())
			{
				case 1:
				if(carga == 0)
				{
					printf("Ingrese el nombre del archivo (movies.csv): ");
					fflush(stdin);
					gets(nombreArchivo);
					if(!controller_loadFromText(nombreArchivo, listaMovies))
					{
						carga = 1;

					}
				}
				else
				{
					printf("No se puede abrir otro archivo en este momento ya que se sobreescribirian\n");
				}
				break;

				case 2:
					if(carga == 0)
					{
						printf("Aun no se ha cargado ningun archivo\n");
					}
					else
					controller_ListMovies(listaMovies);
				break;

				case 3:
					asignarGenero(listaMovies,asignarAleatorios);
				break;

				case 4:
				if(carga == 0)
				{
					printf("Aun no se ha cargado ningun archivo\n");
				}
				else
				{
					filtradoPorGenero(listaMovies);
				}
				break;

				case 5:
				if(carga == 0)
				{
					printf("Aun no se ha cargado ningun archivo\n");
				}
				else
					archivoPelisOrdenadas(listaMovies);
				break;

				case 6:
					printf("Si desea seguir escribe S sino N: \n");
					fflush(stdin);
					scanf("%c", &seguir);
				break;

				default:
					printf("error, ingrese del 1 al 6\n");
				break;
			}

	}while(seguir == 'n');

	ll_deleteLinkedList(listaMovies);

return 0;
}
