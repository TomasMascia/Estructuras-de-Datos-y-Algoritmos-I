#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(int argc, char *argv[]) {

  SList lista = slist_crear();
 
  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_final(lista, 4);

  SList lista2 = slist_crear();

  lista2 = slist_agregar_inicio(lista2, 5);
  lista2 = slist_agregar_inicio(lista2, 2);
  lista2 = slist_agregar_inicio(lista2, 7);
  lista2 = slist_agregar_final(lista2, 4);


  slist_recorrer(lista, imprimir_entero);
  puts("");

  SList listafinal = slist_intersecar(lista, lista2);

  slist_recorrer(listafinal, imprimir_entero);
  puts("");


  slist_destruir(lista);
  slist_destruir(lista2);
  
  return 0;
}
