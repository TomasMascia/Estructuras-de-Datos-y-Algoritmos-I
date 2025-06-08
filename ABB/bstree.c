#include "bstree.h"
#include <assert.h>
#include <stdlib.h>


// Estructura del nodo del arbol de busqueda binaria.
// Tiene un puntero al dato (dato),
// un puntero al nodo raiz del subarbol izquierdo (izq),
// y un puntero al nodo raiz del subarbol derecho (der).

struct _BST_Nodo {
  void *dato;
  struct _BST_Nodo *izq;
  struct _BST_Nodo *der;
};


// bstee_crear: Retorna un arbol de busqueda binaria vacio
BSTree bstee_crear() { return NULL; }


// bstree_destruir: Destruye el arbol y sus datos
void bstree_destruir(BSTree raiz, FuncionDestructora destr) {
  if (raiz != NULL) {
    bstree_destruir(raiz->izq, destr);
    bstree_destruir(raiz->der, destr);
    destr(raiz->dato);
    free(raiz);
  }
};

// 6)
// bstree_buscar: Retorna 1 si el dato se encuentra y 0 en caso contrario
int bstree_buscar(BSTree arbol, void *dato, FuncionComparadora comp) {
  if (arbol == NULL)
    return 0;
  else if (comp(dato, arbol->dato) == 0) // raiz->dato == dato
    return 1;
  else if (comp(dato, arbol->dato) < 0) // dato < raiz->dato
    return bstree_buscar(arbol->izq, dato, comp);
  else // raiz->dato < dato
    return bstree_buscar(arbol->der, dato, comp);
}

// 7)
// bstree_insertar: Inserta un dato no repetido en el arbol, manteniendo la propiedad del arbol de busqueda binaria
BSTree bstree_insertar(BSTree raiz, void *dato, FuncionCopiadora copia,FuncionComparadora comp) {
  if (raiz == NULL) { // insertar el dato en un nuevo nodo
    
    struct _BST_Nodo *nuevoNodo = malloc(sizeof(struct _BST_Nodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->izq = nuevoNodo->der = NULL;

    return nuevoNodo;
  } 
  else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    raiz->izq = bstree_insertar(raiz->izq, dato, copia, comp);
  else if (comp(dato, raiz->dato) > 0) // raiz->dato < dato
    raiz->der = bstree_insertar(raiz->der, dato, copia, comp);
  // si el dato ya se encontraba, no es insertado
  return raiz;
}


// 8)
// bstree_recorrer: Recorrido DSF del arbol
void bstree_recorrer(BSTree raiz, BSTreeRecorrido orden,FuncionVisitanteExtra visita, void *extra) {
  if (raiz != NULL){

    if (orden == BTREE_RECORRIDO_PRE)
      visita(raiz->dato, extra);
      
    bstree_recorrer(raiz->izq, orden, visita, extra);
    
    if (orden == BTREE_RECORRIDO_IN)
      visita(raiz->dato, extra);

    bstree_recorrer(raiz->der, orden, visita, extra);
    
    if (orden == BTREE_RECORRIDO_POST)
      visita(raiz->dato, extra);
  }
}


// 9)
// bstree_eliminar: elimina el nodo que contiene el dato dado
BSTree bstree_eliminar(BSTree raiz, void *dato, FuncionComparadora comp, FuncionDestructora destr) {
  if (raiz == NULL) return NULL;

  int comparacion = comp(dato, raiz->dato);

  if (comparacion < 0){
    raiz->izq = bstree_eliminar(raiz->izq, dato, comp, destr);} 
  
  else if (comparacion > 0){
    raiz->der = bstree_eliminar(raiz->der, dato, comp, destr);} 
  
  else {
    // Nodo encontrado
    
    if (raiz->izq == NULL && raiz->der == NULL) {
      // Sin hijos
      destr(raiz->dato);
      free(raiz);
      return NULL;}

    else if (raiz->izq == NULL) {
      // Solo hijo derecho
      BSTree temp = raiz->der;
      destr(raiz->dato);
      free(raiz);
      return temp;}

    else if (raiz->der == NULL) {
      // Solo hijo izquierdo
      BSTree temp = raiz->izq;
      destr(raiz->dato);
      free(raiz);
      return temp;}

    else {
      // Dos hijos
      BSTree sucesor = minimo_nodo(raiz->der);
      void *dato_sucesor = sucesor->dato;

      raiz->dato = dato_sucesor;

      raiz->der = bstree_eliminar(raiz->der, dato_sucesor, comp, destr);
    }
  }

  return raiz;
}

// 10)
// Implemente bstree k esimo menor que retorne el k-´esimo menor elemento del ABB, con k par´ametro.
// Intente no usar estructuras auxiliares. Ayuda: piense que recorrido del arbol (preorden, inorden, postor-
// den) procesa los elementos de menor a mayor.
// Mencione que informacion adicional podria almacenar en los nodos que permita realizar esta operacion
// de manera mas eficiente. Es decir, que en cada llamada sea posible saber en cual de los subarboles esta
// el nodo buscado, evitando explorar ambos.

// Función auxiliar recursiva
void k_esimo_menor_aux(BSTree arbol, int k, int* contador, int* resultado) {
    
  if (arbol == NULL || *resultado != -1)
      return;

    k_esimo_menor_aux(arbol->izq, k, contador, resultado);

    (*contador)++;
    if (*contador == k) {
        *resultado = arbol->dato;
        return;
    }

    k_esimo_menor_aux(arbol->der, k, contador, resultado);
}

// principal
void bstree_k_esimo_menor(BSTree arbol, int k){
  int contador = 0;
  int resultado = -1;
  k_esimo_menor_aux(arbol, k, &contador, &resultado);
  return resultado;
}

// 11)
// valida si un arbol es ABB o no

int btree_validar(BSTree arbol, void *min, void *max, FuncionComparadora comp) {
  
  if (arbol == NULL) {
    return 1;
  }

  if ((min != NULL && comp(arbol->dato, min) <= 0) || (max != NULL && comp(arbol->dato, max) >= 0)) {
    return 0;
  }
  
  return btree_validar(arbol->izq, min, arbol->dato, comp) && btree_validar(arbol->der, arbol->dato, max, comp);
}