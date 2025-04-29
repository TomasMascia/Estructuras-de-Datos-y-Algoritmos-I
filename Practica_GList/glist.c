#include "glist.h"
#include <assert.h>
#include <stdlib.h>


// Devuelve una lista vacía.

GList glist_crear() { return NULL; }


// Destruccion de la lista.
// destroy es una función que libera el dato almacenado.

void glist_destruir(GList list, FuncionDestructora destroy) {
  GNode *nodeToDelete;
  while (list != NULL) {
    nodeToDelete = list;
    list = list->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }
}

// Determina si la lista es vacía.

int glist_vacia(GList list) { return (list == NULL); }


// Agrega un elemento al inicio de la lista.
// copy es una función que retorna una copia física del dato.

GList glist_agregar_inicio(GList list, void *data, FuncionCopia copy) {
  GNode *newNode = malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->next = list;
  newNode->data = copy(data);
  return newNode;
}


// Recorrido de la lista, utilizando la funcion pasada.
 
void glist_recorrer(GList list, FuncionVisitante visit) {
  for (GNode *node = list; node != NULL; node = node->next)
    visit(node->data);
}

// Dada una lista general filtra con un predicado y devuelve la listanueva

GList glist_filtrar(GList lista, FuncionCopia c, Predicado p){
  
  GList listanueva = NULL;
  
  for(; lista != NULL; lista = lista->next){
    if(p(lista->data)){
      listanueva = glist_agregar_inicio(listanueva, lista->data, c);
    }
  }
  return listanueva;
}


// EJERCICIO 8 
// a)

SGList sglist_crear(){
  return NULL;
}

// b)

void sglist_destruir(SGList lista, FuncionDestructora c){
  glist_destruir(lista, c);
}

// c)
int sglist_vacia(SGList lista){
  return lista == NULL;
}

// d)
sglist_recorrer(GList lista, FuncionVisitante visitar){

  for(;lista != NULL; lista = lista->next){
    glist_recorrer(lista, visitar);
  }
}

// e)
SGList sglist_insertar(SGList lista, void * dato, FuncionCopia copia, FuncionComparadora comparadora){
  SGList nuevalista = malloc(sizeof(SGList));
  nuevalista->data = dato;

  if(lista == NULL){
    nuevalista->next = lista;
    return nuevalista;
  }

  SGList actual = lista;
    while (actual->next != NULL && cmp(dato, actual->next->data) > 0) {
        actual = actual->next;
    }
    
    nuevalista->next = actual->next;
    actual->next = nuevalista;
    return lista;
}

// f)
int sglist_buscar(SGList lista, void* dato, FuncionComparadora cmp) {
  SGList actual = lista;
  while (actual != NULL && cmp(dato, actual->data) > 0) {
      actual = actual->next;
  }
  return (actual != NULL && cmp(dato, actual->data) == 0);
}
// g)
SGList sglist_arr(void ** arr, int longitud, FuncionCopia copia, FuncionComparadora cmp){
  SGList lista = glist_crear();

  for(int i = 0; i < longitud ; i++){
    lista = sglist_insertar(lista,arr[i],copia,cmp);
  }
  return lista;
}
