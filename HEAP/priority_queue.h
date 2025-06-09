#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "heap.h"


typedef BHeap PQueue;


/**
 * Crea una cola de prioridad con la funcion que compara
 * las distintas prioridades.
*/
PQueue pqueue_crear();

/**
 * Determina si una cola de prioridad esta vacia.
*/
int pqueue_vacia(PQueue pqueue);

/**
 * Nos devuelve el elemento mas prioritario, al mismo tiempo que lo elimina
 * de la cola de prioridad.
*/
void* pqueue_maximo(PQueue pqueue);

/**
 * Dado un dato y una prioridad, inserta al dato en la cola de prioridad
 * con dicha prioridad dada.
*/
void pqueue_insertar(PQueue pqueue, void* dato, int prioridad);


#endif /* __PRIORITY_QUEUE_H__*/
