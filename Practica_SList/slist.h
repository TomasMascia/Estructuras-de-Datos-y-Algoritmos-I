#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_a

int slist_longitud(SList lista);

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_b

void slist_concatenar(SList *lista1,SList lista2);

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_c

void slist_insertar(SList *lista, int posicion, int dato); 

//______________________________________________________________________________________________________________________________________________


// Ejercicio 2_d

void slist_eliminar(SList *lista, int posicion);

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_e

int slist_contiene(SList lista, int objeto);

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_f

int slist_indice(SList lista, int objeto);

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_g

SList slist_intersecar(SList lista1, SList lista2); 

SList slist_intersecar2(SList lista1, SList lista2);

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_h

SList slist_ordenar(SList lista, int *funcion); 

//______________________________________________________________________________________________________________________________________________


// Ejercicio 2_i

SList slist_reverso(SList lista);

// forma de gaspo

SList slist_reverso2(SList lista);

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_k

SList slist_intercalar(SList lista1,SList lista2); 

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_l

void slist_partir(SList lista);

//______________________________________________________________________________________________________________________________________________

#endif /* __SLIST_H__ */
