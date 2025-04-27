#include <stdlib.h>
#include <stdio.h>


// PRACTICA LISTAS 
// Ejercicio 3

// Considere la siguiente definicion de listas simplemente enlazadas de enteros, que mantiene adicional-
// mente un puntero al ultimo elemento de la lista:

typedef struct _SNodo {
    int dato;
    struct _SNodo *sig;
    } SNodo;

typedef struct SList {
    SNodo *primero;
    SNodo *ultimo;
    } SList;

// Reimplemente para este caso las funciones slist crear, slist agregar inicio y slist agregar final.
// ¿Detecta alguna ventaja o desventaja con la nueva definicion?

// Implemento crear una lista con esta nueva definicion
// slist_crear() crea una lista vacia

SList slist_crear(){
    SList listanueva;
    listanueva.primero = NULL;
    listanueva.ultimo = NULL;

    return listanueva;
}

// Implemento agregar al principio o inicio

SList slist_agregar_inicio(SList lista, int objeto){
    
    SNodo * nuevonodo = malloc(sizeof(SNodo));
    nuevonodo->dato = objeto;

    if(lista.primero == NULL){
        nuevonodo->sig = NULL;
        lista.primero = nuevonodo;
        lista.ultimo = nuevonodo;
    }
    else{
        nuevonodo->sig = lista.primero;
        lista.primero = nuevonodo;
    }
}

// Implemento agregar al final

SList slist_agregar_final(SList lista, int objeto){
    
    SNodo * nuevonodo = malloc(sizeof(SNodo));
    nuevonodo->dato = objeto;
    nuevonodo->sig = NULL; 

    if(lista.primero == NULL){
        nuevonodo->sig = NULL;
        lista.primero = nuevonodo;
        lista.ultimo = nuevonodo;
    }
    else{
        lista.ultimo->sig = nuevonodo;
        lista.ultimo = nuevonodo;
    }
}

//