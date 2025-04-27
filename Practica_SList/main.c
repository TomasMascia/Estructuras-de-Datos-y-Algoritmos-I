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
  lista = slist_agregar_final(lista, 1);

   SList lista2 = slist_crear();

   lista2 = slist_agregar_inicio(lista2, 5);
   lista2 = slist_agregar_inicio(lista2, 2);
   lista2 = slist_agregar_inicio(lista2, 7);


  //printf("%d\n", slist_contiene(lista, 22));
  
  //SList listanueva = slist_reverso2(lista);

  slist_recorrer(lista, imprimir_entero);
  puts("");

  slist_recorrer(lista2, imprimir_entero);
  puts("");


  //SList nuevalista = slist_intercalar(lista, lista2);

  //slist_recorrer(nuevalista, imprimir_entero);
  //puts("");



  slist_destruir(lista);
  // slist_destruir(lista2);
  
  return 0;
}
