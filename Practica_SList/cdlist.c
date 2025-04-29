#include <stdio.h>
#include <stdlib.h>

// 5. De una implementacion de listas doblemente enlazadas de enteros circulares. ¿Es necesario mantener
// un puntero al ultimo elemento de la lista? Llame a los ficheros como cdlist.h y cdlist.c. Implemente
// cdlist recorrer de manera que solo ejecute una pasada sobre cada elemento.

typedef void (*FuncionVisitante) (int dato);

typedef struct _DNodo {
    int dato;
    struct _DNodo* sig;
    struct _DNodo* ant;
    } DNodo;

// Solo necesitamos el puntero al primero
typedef DNodo* CDList;


typedef enum {
    DLIST_RECORRIDO_HACIA_ADELANTE,
    DLIST_RECORRIDO_HACIA_ATRAS
    } DListOrdenRecorrido;


CDList cdlist_crear(){
    return NULL;
}

void cdlist_destruir(CDList lista){
    DNodo * nodoEliminar = lista->sig;
    DNodo * inicio = lista;
    DNodo * temp;

    while(nodoEliminar != inicio){
        temp = nodoEliminar;
        nodoEliminar = nodoEliminar->sig;
        free(temp);
    }
}

int cdlist_vacia(CDList lista){
    return lista == NULL;
}

void cdlist_agregar(CDList lista, int objeto){
    DNodo * nodonuevo = malloc(sizeof(DNodo));
    nodonuevo->dato = objeto;

    if (lista == NULL){
        
        lista->sig = nodonuevo;
        lista->ant = nodonuevo;
        lista = nodonuevo;
    
    }
    else{
        nodonuevo->sig = lista;
        nodonuevo->ant = lista->ant;

        lista->ant->sig = nodonuevo;
        lista->ant = nodonuevo;
        lista = nodonuevo;
    }
}

void cdlist_recorrer(CDList lista, FuncionVisitante visit, DListOrdenRecorrido direccion){
    
}

int cdlist_longitud(CDList lista);