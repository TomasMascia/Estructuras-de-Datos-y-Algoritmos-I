#include "priority_queue.h"
#include <stdlib.h>

#define INITIAL_SIZE 100 // Definimos un tamanio inicial para la PQueue


struct _PDato {

  void* dato;
  int prioridad;

};

// Implementamos un tipo de dato que encierra al dato con su prioridad
typedef struct _PDato* PDato;


static void* id(void* dato) { return dato; }


static void skip_destroy(void* dato) { return; }


static int PDatos_comparar(void* dato1, void* dato2) {

  return ((PDato) dato1)->prioridad - ((PDato) dato2)->prioridad;
}


/**
 * Crea una cola de prioridad con la funcion que compara
 * las distintas prioridades.
*/
PQueue pqueue_crear() {

  // Almacenaremos y devolveremos los mismos datos que nos da el usuario
  return bheap_crear(INITIAL_SIZE, PDatos_comparar, id, skip_destroy);
}


/**
 * Determina si una cola de prioridad esta vacia.
*/
int pqueue_vacia(PQueue pqueue) { return bheap_es_vacio(pqueue); }


/**
 * Nos devuelve el elemento mas prioritario, al mismo tiempo que lo elimina 
 * de la cola de prioridad.
*/
void* pqueue_maximo(PQueue pqueue) { 
  
  PDato dato_prioritario = (PDato) bheap_maximo(pqueue);

  bheap_eliminar(pqueue);

  void* dato = dato_prioritario->dato;
  free(dato_prioritario);

  return dato;
}

/**
 * Dado un dato y una prioridad, inserta al dato en la cola de prioridad
 * con dicha prioridad dada.
*/
void pqueue_insertar(PQueue pqueue, void* dato, int prioridad) {

  PDato dato_insertado = malloc(sizeof(struct _PDato));

  dato_insertado->dato = dato;
  dato_insertado->prioridad = prioridad;

  bheap_insertar(pqueue, dato_insertado);
}
  