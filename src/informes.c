#include <stdio.h>
#include <stdlib.h>
#include "infomes.h"
#include "pelicula.h"
#include "controller.h"


int filtradoPorGenero(LinkedList* pListaMovies)
{
	int retorno = -1;
	int respuesta;

		if(pListaMovies!= NULL)
		{

					do
					{
						printf("ingrese 1 para filtrar en drama\n"
								"ingrese 2 para filtrar en comedia\n"
								"ingrese 3 para filtrar en terror\n"
								"ingrese 4 para filtrar en accion\n");
						scanf("%d",&respuesta);

						switch(respuesta)
						{

							case 1:
								archivoDrama(pListaMovies);
							break;

							case 2:
								archivoComedy(pListaMovies);
							break;

							case 3:
								archivoHorror(pListaMovies);
							break;

							case 4:
								archivoAction(pListaMovies);
							break;

							case 5:
							break;

						}
						retorno = 0;

						printf("Creando Archivo.\nIngrese 1 para ir al menu\n");
						scanf("%d", &respuesta);

					}while(respuesta!=1);

		}
	    return retorno;
}
