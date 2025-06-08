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

//int slist_longitud(SList lista){
//
//  int contador = 0;
//  for(SNodo *nodo = lista ; nodo != NULL; nodo = nodo->sig ){
//    contador++;
//  }
//  return contador;
// }
int slist_longitud(SList lista){
  int contador = 0;
  while(lista != NULL){
    lista = lista->sig;
    contador ++;
  }
  return contador;
}


//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_b

//void slist_concatenar(SList *lista1, SList lista2){
//  SList nodo = *lista1;
//  for(; nodo->sig != NULL; nodo = nodo->sig){
//  }  
//  nodo->sig = lista2;                                                     
//}

void slist_concatenar(SList lista1, SList lista2){
  while(lista1->sig != NULL){
    lista1 = lista1->sig;
  }
  lista1->sig = lista2;
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


//int slist_contiene(SList lista, int objeto){
//  
//  for(SNodo *nodo = lista;nodo != NULL; nodo = nodo->sig){
//    if(nodo->dato == objeto){
//      return 1;
//    }
//  }
//  return 0;
//}
int slist_contiene(SList lista, int obj){
  while(lista->dato != obj || lista != NULL){
    lista = lista->sig;
  }
  return (lista->dato == obj);
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
// OTRA MANERA DE HACERLO

SList slist_intersecar2(SList lista1,SList lista2){
  
  SList listanueva = slist_crear();

  for(SNodo *nodo = lista1; nodo != NULL; nodo = nodo->sig){
    if(slist_contiene(lista2, nodo->dato)){
      slist_agregar_inicio(listanueva, nodo->dato);
    }
  }
  return listanueva;
}



//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_h

int mayor_menor(int a, int b){
  if(a > b){
    return 1;
  }
  else if (a < b){
    return 0;
  }
  else{
    return a;
  }
}

SList slist_ordenar(SList lista, int *funcion){
}

//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_i

SList slist_reverso(SList cabeza) {
  SList anterior = NULL;
  SList actual = cabeza;
  SList siguiente = NULL;

  while (actual != NULL) {
      siguiente = actual->sig;
      actual->sig = anterior;  
      anterior = actual;
      actual = siguiente;
  }

  return anterior;
}

// Forma de gaspo
SList slist_reverso2(SList lista) {
  SList resultado = slist_crear();

  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig){
    resultado = slist_agregar_inicio(resultado, nodo->dato);
  }

  return resultado;
}


//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_k

SList slist_intercalar(SList lista1, SList lista2){
  SList intercalado = slist_crear();

  while(lista1 != NULL || lista2 != NULL ){
    if (lista1 != NULL) {
      intercalado = slist_agregar_final(intercalado, lista1->dato);
      lista1 = lista1->sig;
  }
    if (lista2 != NULL) {
      intercalado = slist_agregar_final(intercalado, lista2->dato);
      lista2 = lista2->sig;
  }
}

return intercalado;
}
//______________________________________________________________________________________________________________________________________________

// Ejercicio 2_l

//void slist_partir(SList lista){
//  
//  if (lista == NULL || lista->sig == NULL){
//    return NULL;
//  }
//  
//  int longitud = slist_longitud(lista);
//  int mitad = 0;
//
//  if(longitud % 2 == 0){
//    int mitad = longitud / 2;
//  }
//  else{
//    int mitad = (longitud / 2) + 1;
//  }
//  
//  SList primera = slist_crear();
//  SList segunda = slist_crear();
//
//  for(int i = 0; i < mitad;i++){
//    SNodo *nodo = lista;
//    segunda = slist_agregar_final(segunda, (nodo->dato));
//  }
//}
//______________________________________________________________________________________________________________________________________________


// IMPLEMENTAMOS ESTA DEF

