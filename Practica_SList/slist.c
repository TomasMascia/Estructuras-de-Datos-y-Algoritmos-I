#include "slist.h"
#include <stdlib.h>
#include <stdio.h>

SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}


//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_a

int slist_longitud(SList lista){

  int contador = 0;
  for(SNodo *nodo = lista ; nodo != NULL; nodo = nodo->sig ){
    contador++;
  }
  return contador;
}

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_b

void slist_concatenar(SList* lista1, SList lista2){
  SList nodo = *lista1;
  for(; nodo->sig != NULL; nodo = nodo->sig){
  }  
  nodo->sig = lista2;
}

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_c

void slist_insertar(SList *lista, int posicion, int objeto){

  int largo = slist_longitud(*lista);
  
  if(posicion <= 0 || *lista == NULL){
    *lista = slist_agregar_inicio(*lista, objeto);
  }
  else if (posicion == largo)
  {
    *lista = slist_agregar_final(*lista, objeto);
  }
  else{
    
    SNodo *nuevoNodo = malloc(sizeof(SNodo));
    nuevoNodo->dato = objeto;

    SNodo *nodo = *lista;

    int contador = 0;

    for(;nodo != NULL; nodo = nodo->sig){
      if(contador == posicion -1){
        nuevoNodo->sig = nodo->sig; 
        nodo->sig = nuevoNodo;
      }
      contador++;
    }
  }
}
//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_d


void slist_eliminar(SList *lista, int posicion){
  
  int largo = slist_longitud(*lista);

  int contador = 0;
  SNodo *nodo = *lista;

  if(posicion <= 0){
    nodo->sig = nodo;
  }
  else{
 
  for(;nodo != NULL;nodo = nodo->sig){
    
    if(contador == posicion -1){
      nodo->sig = nodo->sig->sig;
    }
    contador++;
    printf("%d\n", nodo->dato);
  }
  
}
}
//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_e


int slist_contiene(SList lista, int objeto){
  
  for(SNodo *nodo = lista;nodo != NULL; nodo = nodo->sig){
    if(nodo->dato == objeto){
      return 1;
    }
  }
  return 0;
}
//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_f

int slist_indice(SList lista, int objeto){
  int contador = 0;
  for(SNodo *nodo = lista;nodo != NULL; nodo = nodo->sig){
    if(nodo->dato == objeto){
      return contador;
    }
    else{
      contador++;
    }
  }
  return -1;
}


//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_g

SList slist_intersecar(SList lista1, SList lista2){

  SList listanueva = slist_crear();

  for(SNodo *nodo1 = lista1;nodo1 != NULL; nodo1 = nodo1->sig){
    for(SNodo *nodo2 = lista2;nodo2 != NULL; nodo2 = nodo2->sig){
      if(nodo1->dato == nodo2->dato){
        slist_agregar_inicio(listanueva, nodo1->dato);
      }
    }
  }
  return listanueva;
}

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_h

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_i

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_j

//______________________________________________________________________________________________________________________________________________