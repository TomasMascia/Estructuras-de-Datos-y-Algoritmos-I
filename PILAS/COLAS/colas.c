#include <stdlib.h>

typedef struct NodoCola {
    int dato;
    struct NodoCola *sig;
} NodoCola;

typedef struct Cola {
    NodoCola *primero;
    NodoCola *ultimo;
} *Cola;

// Funciones de cola 



// Crear una cola vacía
Cola cola_crear() {
    Cola cola = malloc(sizeof(struct Cola));
    if (!cola) return NULL;
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}

// Verifica si la cola está vacía
int cola_es_vacia(Cola cola) {
    return cola->primero == NULL;
}

// Encolar un BTree
void cola_encolar(Cola cola, BTree dato) {
    NodoCola *nuevo = malloc(sizeof(NodoCola));
    if (!nuevo) return;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    if (cola->ultimo)
        cola->ultimo->sig = nuevo;
    else
        cola->primero = nuevo;

    cola->ultimo = nuevo;
}



// Desencolar un BTree
BTree cola_desencolar(Cola cola) {
    if (cola_es_vacia(cola)) return NULL;

    NodoCola *tmp = cola->primero;
    BTree dato = tmp->dato;

    cola->primero = tmp->sig;
    if (!cola->primero)
        cola->ultimo = NULL;

    free(tmp);
    return dato;
}

// Destruir la cola
void cola_destruir(Cola cola) {
    while (!cola_es_vacia(cola))
        cola_desencolar(cola);
    free(cola);
}


