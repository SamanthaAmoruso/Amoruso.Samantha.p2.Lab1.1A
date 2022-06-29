#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!= NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;

		while(nodeIndex > 0)
		{
			pNode = pNode->pNextNode;
			nodeIndex--;
		}
	}

    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    Node* newNode = NULL;
    Node* previousNode = NULL;
    if(this!= NULL && nodeIndex >=0 && nodeIndex <= ll_len(this))
    {
    	newNode = (Node*) malloc(sizeof(Node));
    	if(newNode != NULL)
    	{
    		newNode->pElement = pElement;
    		newNode->pNextNode = getNode(this, nodeIndex);
    		if(nodeIndex == 0)
    		{
    			this->pFirstNode = newNode;
    		}
    		else
    		{
    			previousNode = getNode(this,nodeIndex-1);
    			previousNode->pNextNode = newNode;
    		}
    		returnAux = 0;
    		this->size++;
    	}
    }

    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	addNode(this, ll_len(this), pElement);
    	returnAux = 0;
    }
    return returnAux;
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    Node *auxNode = NULL;

    if(this!= NULL && index >= 0 && index < ll_len(this))
    {
    	auxNode = getNode(this,index);
    	if(auxNode != NULL)
    	{
    		returnAux = auxNode->pElement;
    	}
    }
    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxNode = getNode(this, index);
    	if(auxNode != NULL)
    	{
    		auxNode->pElement = pElement;
    		returnAux = 0;
    	}
    }
    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* auxNode = NULL;
    Node* nodoAnterior = NULL;
    if(this != NULL && index >=0 && index <ll_len(this) && ll_len(this)>0)
    {
    	auxNode = getNode(this,index);
    	if(auxNode != NULL)
    	{
    		if(index == 0)
			{
				this->pFirstNode = auxNode->pNextNode;// cambio el puntero del primer nodo de la lista para que apunte al next node del nodo a eliminar, que como
			}                                          // es el primero es 0
			else
			{
				nodoAnterior = getNode(this,index-1);
				if(nodoAnterior != NULL)
				{
					nodoAnterior->pNextNode = auxNode->pNextNode;//apunto el next node del nodo anterior al next node del nodo a eliminar

				}
			}
    		free(auxNode); // libero
			this->size--; // reduzco
			returnAux = 0;

		}
   	}


    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!= NULL)
    {
    	while(ll_len(this) > 0)// el ultimo se convierte en el primero a eliminar
    	{
    		returnAux = ll_remove(this,0);// elimina siempre la posicion 0, que cada vez corresponde a un elemento distinto porque la lista se achica
    		if(returnAux)
    		{
    			break;
    		}
    	}

    	returnAux = 0;
    }

    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(!ll_clear(this))
    	{
    		free(this);
    		returnAux = 0;
    	}

    }
    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!= NULL)
    {
    	for(i=0;i < ll_len(this);i++) //itero la lista
    	{

			if(ll_get(this,i) == pElement) // si el elemenyo del nodo coincide con el parametro elementyo
			{
				returnAux = i;// retorno la posicion
			}

    	}
    }
    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!= NULL)
    {
    	int tam = ll_len(this);
    	returnAux = 1;
    	if(tam){
    		if(tam>0)
    		{
    			returnAux= 0;
    		}
    	}
    	else
    	{
    		returnAux = 1;
    	}

    }

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0)
	{
		returnAux = addNode(this, index, pElement); //agrega el elemento en el indice parametrizado
	}
    return returnAux;
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = ll_get(this,index); // devuelve el elemento del indice
    	ll_remove(this,index); // lo borra
    }

    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;
    	if(ll_indexOf(this,pElement) != -1) // si el indice del elemento del parametro
    	{                                      //es diferente de -1, pertenece a una posicion de la lista
    		returnAux = 1;
    	}

    }
    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    if(this!=NULL && this2 != NULL)
    {
    	returnAux = 1; // retorno 1 porque las listas son validas y en caso de que no sea cierto, el retorno cambia despues

    	for(i=0;i<ll_len(this2);i++) //itera hasta el len de la lista 2
    	{
    		if(!ll_contains(this,ll_get(this2,i))) //si la funcion contains devuelve que el elemento i de la lista 2 no esta en la lista 1
    		{                                     //cambia el retorno
    			returnAux = 0;
    			break;
    		}
    	}
    }
    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;

    if(this!= NULL)
    {
    	if(from >=0 && from < to &&  to <= ll_len(this))
    	{
    		cloneArray = ll_newLinkedList(); // genera una nueva lista

    		if(cloneArray != NULL)
    		{
    			for(i = from; i <to;i++) // itera desde from a to
    			{
    				pElement = ll_get(this,i); //consigue el elememto en la posicion i de la lista clonada
    				ll_add(cloneArray,pElement);// y lo añade a la lista nueva
    			}
    		}
    	}
    }
    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int i;
    void* pElement;
    int from=0; //setea el from en 0
    int to = ll_len(this);// setea el final de la iteracion en el final de la lista a clonar

    if(this != NULL)
    {
    	if(from <= ll_len(this) && to > from)
    	{
    		cloneArray = ll_newLinkedList(); //crea una lista clon

    		if(cloneArray != NULL)
    		{
    			for(i=from; i< to; i++) // itera desde from a to
    			{
    				pElement = ll_get(this,i); //consigue el elemento i de la lista
    				ll_add(cloneArray,pElement); // lo añade a la lista clonada
    			}
    		}
    	}
    }
    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    void* aux;

    if(this != NULL && pFunc != NULL && order >=0 && order <=1)
    {
    	for(i = 0;i<(ll_len(this) -1);i++) //hago un burbujero
    	{
    		for(j=i+1; j< ll_len(this);j++)
    		{
    			if(order == 1 && pFunc(ll_get(this,i), ll_get(this,j))>0)
    			{
    				aux = ll_get(this,i);
    				ll_set(this,i, ll_get(this,j)); // hago un swap de las posiciones i y j segun el orden 1
    				ll_set(this,j,aux);

    			}
    			else
    			{
    				if(order == 0 && pFunc(ll_get(this,i), ll_get(this,j))< 0)
    				{
    					aux = ll_get(this,i);
    					ll_set(this,i,ll_get(this,j)); // hago un swap de las posiciones i y j segun el orden 0
    					ll_set(this,j,aux);
    				}
    			}
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;

}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* filterList = NULL;
	void* aux = NULL;
	int tam;
	if(this != NULL && pFunc != NULL)
	{
		filterList = ll_newLinkedList();
		if(filterList != NULL)
		{
			tam = ll_len(this);
			for(int i =0;i<tam;i++)
			{
				aux = ll_get(this,i);
				if(pFunc(aux))
				{
					if(ll_add(filterList,aux))
					{
						ll_deleteLinkedList(filterList);
						filterList = NULL;
					}
				}
			}
		}
	}
	return filterList;
}

LinkedList* ll_map(LinkedList* this, int(*pFunc) (void*))
{
	int func;
	LinkedList* listaN = ll_newLinkedList();
	void* auxElement= NULL;

	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0;i< ll_len(this);i++)
		{
			auxElement = ll_get(this,i);
			func = pFunc(auxElement);
			if(func == 0)
			{
				ll_add(listaN,auxElement);
				//retorno = 0;
			}
			else
			{
				//retorno = -1;
				break;
				listaN = NULL;
			}
		}
	}
	return listaN;
}
