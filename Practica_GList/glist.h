#ifndef __GLIST_H__
#define __GLIST_H__

typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);

typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef GNode *GList;

typedef GList SGList;

typedef int (*Predicado) (void *dato);
typedef int (*FuncionComparadora)(void *, void*);

//Devuelve una lista vacía.
GList glist_crear();


//Destruccion de la lista.
void glist_destruir(GList lista, FuncionDestructora destruir);


//Determina si la lista es vacía.
int glist_vacia(GList lista);


//Agrega un elemento al inicio de la lista.
GList glist_agregar_inicio(GList lista, void *dato, FuncionCopia copiar);


//Recorrido de la lista, utilizando la funcion pasada.
void glist_recorrer(GList lista, FuncionVisitante visitar);

// filtra una lista viendo si se cumple el predicado
GList glist_filtrar(GList lista, FuncionCopia c, Predicado p);


// EJERCICIO 8 

// a)retorna una lista ordenada vacıa.
SGList sglist_crear();


// b) destruye una lista ordenada.
void sglist_destruir(SGList, FuncionDestructora);
  
// c) dice si esta vacia.
int sglist_vacia(SGList lista);

// d) aplica la funcion visitante a cada elemento de la lista.
sglist_recorrer(GList, FuncionVisitante);


// e) inserta un nuevo dato en la lista ordenada. La funcion de comparacion es la que determina el criterio de
// ordenacion, su tipo esta declarado como typedef int (*FuncionComparadora)(void *, void
// *), y retorna un entero negativo si el primer argumento es menor que el segundo, 0 si son iguales,
// y un entero positivo en caso contrario.
SGList sglist_insertar(SGList lista, void * dato, FuncionCopia copia, FuncionComparadora comparadora);


// f)
// que busca un dato en la lista ordenada, retornando 1 si lo encuentra y 0 
// en caso contrario (aprovechar que la lista esta ordenada para
// hacer esta busqueda mas eficiente).
int sglist_buscar(GList lista, void * dato, FuncionComparadora cmp);

// g) construye una lista ordenada a partir de un arreglo de elementos y su longitud.
SGList sglist_arr(void **, int, FuncionCopia, FuncionComparadora);


#endif /* __GLIST_H__ */
