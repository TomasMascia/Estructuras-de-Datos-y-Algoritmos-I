#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Practica 1 - Arreglos


// EJERCICIO 1

//1. La mediana de un arreglo ordenado de n n´umeros se define como el elemento del medio cuando n es
//impar y como el promedio de los dos elementos del medio cuando n es par. Por ejemplo,

//mediana([-1.0, 2.2, 2.9, 3.1, 3.5]) = 2.9
//mediana([-1.0, 2.2, 2.9, 3.1]) = 2.55

//Escriba una funcion que reciba un arreglo, no necesariamente ordenado, de numeros y calcule su mediana:

//Puede utilizar la siguiente rutina para ordenar un arreglo de menor a mayor

void bubble_sort(float arreglo[], int longitud) {
    for (int iter = 0 ; iter < longitud - 1 ; iter++) {
        for (int i = 0 ; i < longitud - iter - 1; i++) {
            if (arreglo[i] > arreglo[i + 1]) {
            float aux = arreglo[i];
            arreglo[i] = arreglo[i + 1];
            arreglo[i + 1] = aux;
            }
        }
    }
}

//Nota: La funcion mediana no debe modificar el arreglo original.

float mediana(float *arreglo, int longitud){

    //copiamos el array

    float *copia = (float *)malloc(sizeof(float)* longitud);

    for(int i = 0; i < longitud; i++){
        copia[i] = arreglo[i];
    }

    //ordenamos la copia
    bubble_sort(copia, longitud);

    //inicializo la variable.
    float resultado;

    if(longitud % 2 == 0){
        resultado = ((copia[(longitud/2)-1] + copia[longitud/2])/2);
    }
    else{
        resultado = copia[longitud/2];
    }

    return resultado;
};

//    EJERCICIO 1;

//    float arreglo[] = {-1.0, 2.2, 2.9, 3.1};
//    float *punt = arreglo;
//
//    printf("La mediana es: %.2f\n", mediana(punt, 4));
//    return 0;
//---------------------------------------------------------------------------------------------------------------------------------------------
//    EJERCICIO 2_B;

//    char palabra[] = "hola";
//    char* punt = palabra;
//    
//    string_reverse(punt);
//
//    printf("La palabra reverse es %s\n", punt);


//    EJERCICIO 2_C;

//    EJERCICIO 2_D;

//    char* string1 = "sol";
//    char* string2 = "silla";

//    printf("%d\n",string_compare(string1, string2));


//    EJERCICIO 2_E

//char* string1 = "abc";
//char* string2 = "bac";

//printf("%d\n", string_subcadena(string1, string2));










// EJERCICIO 2

//2. Implemente las siguientes funciones para cadenas de caracteres:

//a) int string len(char* str), que retorne la longitud de la cadena str, excluyendo el caracter nulo (’\0’).

int string_len(char* str){
    int resultado = 0;
    while (str[resultado] != '\0'){
        resultado++;
    }
    return resultado;
}

//    EJERCICIO 2_A;

//    char palabra[] = "hola";
//    char* punt = palabra;
//
//    printf("La longitud es %d\n",string_len(punt));


//---------------------------------------------------------------------------------------------------------------------------------------------



//b) void string reverse(char* str), que invierta la cadena str.

void string_reverse(char* str){
    
    int inicio = 0;
    int final = string_len(str) - 1;

    while (inicio < final){

        char temp = str[inicio];
        str[inicio] = str[final];
        str[final] = temp;
        inicio += 1;
        final -= 1;
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------




//c) int string_concat(char* str1, char* str2, int max), que concatene no mas de max caracteres de la cadena str2 al final de la cadena str1.
// El caracter inicial de str2 debe sobrescribir el caracter nulo de str1. La cadena resultante debe terminar con un caracter nulo. Retorna el
// numero de caracteres copiados.
//Nota: Si str1 no tiene espacio suficiente para almacenar el resultado, el comportamiento queda indefinido

int string_concat(char* str1, char* str2, int max){
    
    int long1 = string_len(str1);
    int long2 = string_len(str2);


}
//---------------------------------------------------------------------------------------------------------------------------------------------
//int string_subcadena(char* str1, char* str2){
//    int long1 = string_len(str1);
//    int long2 = string_len(str2);
//
//    for(int principal = 0; principal < long1; principal ++){
//        for(int secundario = 0; secundario < long2; secundario ++){
//            if (str1[principal] != str2[secundario]){
//                return principal;
//            }
//            else{
//                return -1;
//            }
//        }
//
//    }
//}

//---------------------------------------------------------------------------------------------------------------------------------------------
//d) int string compare(char* str1, char* str2), que compare en orden lexicogr´afico las cadenas
// str1 y str2, y retorne retorne -1 si la primera es menor que la segunda, 0 si son iguales, y 1 si es
// mayor.

int string_compare(char* string1, char* string2){
    int contador = 0;
    
    while (string1[contador] != '\0' && string2[contador] != '\0'){
        if (string1[contador] < string2[contador]) return -1;
        if (string1[contador] > string2[contador]) return 1;
        contador ++;
    }
    if (string1[contador] == '\0' && string2[contador] == '\0') return 0;
    if (string1[contador] == '\0') return -1;
    return 1;
}

//---------------------------------------------------------------------------------------------------------------------------------------------
// e) int string subcadena(char* str1, char* str2), que retorne el ındice de la primera ocurrencia
// de la cadena str2 en la cadena str1. En caso de no ocurrir nunca, retorna −1.

int string_subcadena(char* string1, char* string2){
    
    int cont = 0;

    while (string1[cont] != '\0' && string2[cont] != '\0'){
        
        if(string1[cont] == string2[cont]){
            return cont;
        }
        else{
            cont ++;
        }
    }
    
    return -1;

}
//---------------------------------------------------------------------------------------------------------------------------------------------
// f ) void string unir(char* arregloStrings[], int n, char* sep, char* res), que concatene
// las n cadenas del arreglo arregloStrings, separ´andolas por la cadena sep y almacenando el resultado en res.
// Nota: Si res no tiene espacio suficiente para almacenar el resultado, el comportamiento queda indefinido.

// Ejemplo:
// ["pipe" "gay"] 2 " " res ---> "pipe gay"

void string_unir(char* arregloStrings[], int n, char* sep, char* res) {
    int j = 0;
    int operaciones = 0;
  
    for (int i = 0; i < n; i++) {
      int k = 0;
  
      while (arregloStrings[i][k] != '\0') {
        res[j] = arregloStrings[i][k];
        j++;
        k++;
        operaciones += 2;
      }
  
      if (i < n - 1) {
        int a = 0;
        while (sep[a] != '\0') {
          res[j] = sep[a];
          j++;
          a++;
          operaciones += 2;
        }
      }
    }
  
    res[j] = '\0';
    operaciones++;
  
    printf("Operaciones realizadas: %d\n", operaciones);
  }

  
//---------------------------------------------------------------------------------------------------------------------------------------------


//3. Considere arreglos de enteros definidos a trav´es de una estructura que lleve registro de la capacidad:
typedef struct {
    int* direccion;
    int capacidad;
} ArregloEnteros;

//a) ArregloEnteros* arreglo_enteros_crear(int capacidad);

ArregloEnteros* arreglo_entero_crear(int capacidad){
    
}








int main() {
    


}   

