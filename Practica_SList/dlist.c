#include <stdlib.h>
#include <stdio.h>

// LISTAS DOBLEMENTE ENLAZADAS
// 4. Implemente listas doblemente enlazadas de enteros y sus funciones basicas usando la siguiente
// definicion:


typedef void (*FuncionVisitante) (int dato);

typedef struct _DNodo {
    int dato;
    struct _DNodo* sig;
    struct _DNodo* ant;
    } DNodo;


typedef struct {
    DNodo* primero;
    DNodo* ultimo;
    } DList;


// Llame a los ficheros como dlist.h y dlist.c. En ambos casos implemente dlist recorrer de manera
// que se pueda elegir si se avanza o retrocede en el recorrido, utilizando el tipo


typedef enum {
    DLIST_RECORRIDO_HACIA_ADELANTE,
    DLIST_RECORRIDO_HACIA_ATRAS
    } DListOrdenDeRecorrido;


// Crea una dlist
DList dlist_crear(){

    DList listanueva;
    listanueva.primero = NULL;
    listanueva.ultimo = NULL;

    return listanueva;
}


// Destruye una dlist
void dlist_destruir(DList lista){

    DNodo * nodoDestruir;
    DNodo * temp = lista.primero;

    while (temp != NULL){
        nodoDestruir = temp;
        temp = temp->sig;
        free(nodoDestruir);
    }
    
}
    

// Vacia una dlist
int dlist_vacia(DList lista){
    // PREGUNTAR A GASPO
    return lista.primero == NULL;
}
    

// agrega un nodo al final de la lista
void dlist_agregar_final(DList *lista, int objeto){
    
    DNodo * nuevonodo = malloc(sizeof(DNodo));
    nuevonodo->dato = objeto;

    if(lista->primero == NULL){
        
        lista->primero = nuevonodo;
        lista->ultimo = nuevonodo;
        nuevonodo->ant = NULL;
        nuevonodo->sig = NULL;
    }
    else{
        
        lista->ultimo->sig = nuevonodo;
        nuevonodo->ant = lista->ultimo;
        nuevonodo->sig = NULL;
        lista->ultimo = nuevonodo;
    }

}

// agrega un nodo al inicio de la lista
void dlist_agregar_inicio(DList *lista, int objeto){

    DNodo * nuevonodo = malloc(sizeof(DNodo));
    nuevonodo->dato = objeto;

    if(lista->primero == NULL){

        lista->primero = nuevonodo;
        lista->ultimo = nuevonodo;
        nuevonodo->ant = NULL;
        nuevonodo->sig = NULL;
    }
    else{
        lista->primero->ant = nuevonodo;
        nuevonodo->ant = NULL;
        nuevonodo->sig = lista->primero;
        lista->primero = nuevonodo;
    }
}
    
// recorre la lista dependiendo de la direccion de orden que le des, y aplica la funcion visitante a cada elemento de la lista.
void dlist_recorrer(DList lista, FuncionVisitante visit, DListOrdenDeRecorrido direccion){
    if (direccion == DLIST_RECORRIDO_HACIA_ADELANTE){
        for(DNodo * nodoRecorre = lista.primero; nodoRecorre != NULL; nodoRecorre = nodoRecorre->sig){
            visit(nodoRecorre->dato);
        }
    }
    else{
        for(DNodo * nodoRecorre = lista.ultimo; nodoRecorre != NULL;nodoRecorre = nodoRecorre->ant){
            visit(nodoRecorre->dato);
        }
    }
}
    
// dice que longitud es la lista
int dlist_longitud(DList lista){
    
    int longitud = 0;

    for(DNodo * nodoRecorre = lista.primero; nodoRecorre != NULL; nodoRecorre = nodoRecorre->sig){
        longitud++;
    }

    return longitud;
}