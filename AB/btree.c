
#include <assert.h>
#include <stdlib.h>
#include "btree.h"

struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right) {
  
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));

  assert(nuevoNodo != NULL);
  
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  
  return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */

// b) Pruebe su implementacion utilizando como funcion visitante imprimir entero de test.c

void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit) {

  if (btree_empty(arbol)){
    return;
  }
  
  if (orden == BTREE_RECORRIDO_PRE){
    
    visit(arbol->dato);
    btree_recorrer(arbol->left, orden, visit);
    btree_recorrer(arbol->right, orden, visit);
  }
  

  if (orden == BTREE_RECORRIDO_IN){
    btree_recorrer(arbol->left, orden, visit);
    visit(arbol->dato);
    btree_recorrer(arbol->right, orden, visit);
  }

  if (orden == BTREE_RECORRIDO_POST){
    btree_recorrer(arbol->left, orden, visit);
    btree_recorrer(arbol->right, orden, visit);
    visit(arbol->dato);
  }

  return;
}


//c) Disene una version iterativa para el caso preorden. Ayuda: puede utilizar una pila general para
//guardar los nodos a visitar.

void btree_recorrer_pre_iterativo(BTree arbol, FuncionVisitante visit) {
  if (arbol == NULL) return;

  Pila pila = pila_crear;
  pila_apilar(pila, arbol->dato); 

  while (!pila_es_vacia(pila)){
    BTree nodo = pila_desapilar(pila);
    visit(nodo->dato);

    if(nodo->right) {pila_apilar(pila, nodo->right);}
    if(nodo->left) {pila_apilar(pila, nodo->left);}
  }
  
  pila_destruir(pila);

}



//---------------------------------------------------------------------------------------------
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit) {

  if (btree_empty(arbol)){
    return;
  }

  if (orden == BTREE_RECORRIDO_PRE){
    visit(arbol->dato);
  }
  
  btree_recorrer(arbol->left, orden, visit);

  if (orden == BTREE_RECORRIDO_IN){
    visit(arbol->dato);
  }

  btree_recorrer(arbol->right, orden, visit);

  if (orden == BTREE_RECORRIDO_POST){
    visit(arbol->dato);
  }

  return;
}

// Ejercicio 3-a

int btree_nnodos(BTree arbol){
  if (arbol == NULL){
    return 0;
  }
  else{
    return 1 + btree_nnodos(arbol->left)* btree_nnodos(arbol->right);
  }
}

// Ejercicio 3-b

int btree_buscar(BTree arbol, int datonuevo){
  
  if (arbol == NULL){
    return 0;
  }

  if (arbol->dato == datonuevo){
    return 1;
  }

  return btree_buscar(arbol->left, datonuevo) || btree_buscar(arbol->right, datonuevo);
}

// Ejercicio 3-c

BTree btree_copiar(BTree arbol){
  if (arbol == NULL){
    return NULL;
  }
  
  BTree nuevoarbol = malloc(sizeof());
  nuevoarbol->dato = arbol->dato;
  nuevoarbol->left = btree_copiar(arbol->left);
  nuevoarbol->right = btree_copiar(arbol->right);
  return nuevoarbol;
}

// Ejercicio 3-d

int btree_altura(BTree arbol){
  if (arbol == NULL){
    return -1;
  }
  int left = btree_altura(arbol->left);
  int right = btree_altura(arbol->right);
  return 1 + (left > right ? left : right);
}

// Ejercicio 3-e

int btree_nnodos_profundidad(BTree arbol, int profundidad){
  if (arbol == NULL){
    return 0;
  }
  if (profundidad == 0){
    return 1;
  }
  return btree_nnodos_profundidad(arbol->right, profundidad - 1) + btree_nnodos_profundidad(arbol->left, profundidad - 1);
}

// Ejercicio 3-f

int btree_profundidad(BTree arbol, int valor){
  if (arbol == NULL){
    return -1;
  }
  if (arbol->dato == valor){
    return 0;
  }
  
  int left = btree_profundidad(arbol->left, valor);
  if (left != -1){
    return 1 + left;
  }

  int right = btree_profundidad(arbol->right, valor);
  if (right != -1){
    return 1 + right;
  }
  return -1;
}

// Ejercicio 3-g

int btree_sumar(BTree arbol){
  
  if (arbol == NULL){
    return 0;
  }
  
  return arbol->dato + btree_sumar(arbol->left) + btree_sumar(arbol->right);
}

// Ejercicio 4-a

//void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visit, void *extra){
//
//  if (btree_empty(arbol)){
//    return NULL; 
//  }
//
//  if (orden == BTREE_RECORRIDO_PRE){
//    visit(arbol->dato, extra);
//  }
//  
//  btree_recorrer(arbol->left, orden, visit);
//
//  if (orden == BTREE_RECORRIDO_IN){
//    visit(arbol->dato, extra);
//  }
//
//  btree_recorrer(arbol->right, orden, visit);
//
//  if (orden == BTREE_RECORRIDO_POST){
//    visit(arbol->dato, extra);
//  }
//
//  return;
//
//
//}

// Ejercicio 4-b

//void btree_recorrer_bfs(BTree arbol, FuncionVisitante visit) {
//    if (!arbol) return;
//
//    Cola cola = cola_crear();  // asumimos implementación de cola
//    cola_encolar(cola, arbol);
//
//    while (!cola_es_vacia(cola)) {
//        BTree nodo = cola_desencolar(cola);
//        visit(nodo->dato);
//
//        if (nodo->left)
//            cola_encolar(cola, nodo->left);
//        if (nodo->right)
//            cola_encolar(cola, nodo->right);
//    }
//
//    cola_destruir(cola);
//}

// Ejercicio 5

