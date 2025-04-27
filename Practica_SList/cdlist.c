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
    return NULL
}

void cdlist_destruir(CDList lista);

int cdlist_vacia(CDList lista);

void cdlist_agregar(CDList* lista, int dato);

void cdlist_recorrer(CDList lista, FuncionVisitante visit, DListOrdenRecorrido direccion);

int cdlist_longitud(CDList lista);