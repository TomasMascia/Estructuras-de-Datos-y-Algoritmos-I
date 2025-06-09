#include <stdlib.h>
#include <stdio.h>

// Este es un parcial de Estructura de datos y algoritmos tomado en la UNR en el año 2017
// Es el tema 2 pero el 1 es lo mismo pero con manejar edades 

typedef struct {
    char* nombre, *club;
    int posicionJugador, edad;
} _Jugador;

typedef _Jugador* Jugador;

typedef struct nodo{
    Jugador jug;
    struct nodo* izquierda, * derecha;
} Nodo;

Nodo* agregaJugador(Nodo* inicio, Jugador j);

Nodo* recuperaJugadoresPorPosicion(Nodo* inicio, int posicionMax, int posicionMin);




Nodo* agregaJugador(Nodo* arbol, Jugador jugador){
    if(arbol == NULL){
        Nodo* nuevo = malloc(sizeof(Nodo));
        nuevo->jug = jugador;
        nuevo->derecha = NULL;
        nuevo->izquierda = NULL;
        return nuevo;
    }
    
    if(jugador->posicionJugador <= arbol->jug->posicionJugador){
        arbol->izquierda = agregaJugador(arbol->izquierda, jugador);
    }
    else{
        arbol->derecha = agregaJugador(arbol->derecha, jugador);
    }
    return arbol;
}


Nodo* recuperaJugadoresPorPosicion(Nodo* arbol, int posicionMax, int posicionMin){
    if (arbol == NULL){
        return NULL;
    }

    if (arbol->jug->posicionJugador >= posicionMax){
        recuperaJugadoresPorPosicion(arbol->izquierda, posicionMax, posicionMin);
    }

    if(arbol->jug->posicionJugador <= posicionMax && arbol->jug->posicionJugador >= posicionMin){
        printf("Jugador: %s\n Club: %s\n Edad: %d\n Posicion: %d\n", arbol->jug->nombre, arbol->jug->club, arbol->jug->edad, arbol->jug->posicionJugador);
    }
    if(arbol->jug->posicionJugador <= posicionMin){
        recuperaJugadoresPorPosicion(arbol->derecha, posicionMax,posicionMin);
    }
    return arbol;
}


Jugador crearJugador(char* nombre, char* club, int edad, int posicion) {
    Jugador j = (Jugador)malloc(sizeof(_Jugador));
    j->nombre = nombre;
    j->club = club;
    j->edad = edad;
    j->posicionJugador = posicion;
    return j;
}


int main() {
    Nodo* arbol = NULL;

    if (recuperaJugadoresPorPosicion(NULL, 5, 3) == NULL) {
        printf("OK: Árbol NULL retorna NULL\n");
    }

    if (recuperaJugadoresPorPosicion(arbol, 3, 5) == NULL) {
        printf("OK: Rango inválido retorna NULL\n");
    }

    arbol = agregaJugador(arbol, crearJugador("Lionel", "Inter Miami", 36, 10));
    arbol = agregaJugador(arbol, crearJugador("Dibu", "Aston Villa", 30, 1));
    arbol = agregaJugador(arbol, crearJugador("Otamendi", "Benfica", 35, 2));

    if (recuperaJugadoresPorPosicion(arbol, 5, 3) == NULL) {
        printf("OK: Rango sin jugadores retorna NULL\n");
    }

    printf("Jugadores entre posición 1 y 10:\n");
    recuperaJugadoresPorPosicion(arbol, 10, 1);

    return 0;
}
