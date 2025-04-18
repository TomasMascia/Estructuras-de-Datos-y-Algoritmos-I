#include <stdio.h>
#include <stdlib.h>


void dibujoCuadrado(int tam){
    for(int fila = 0; fila <= tam; fila ++ ){
        printf("x");
        for(int columna = 0; columna <= tam; columna++){
            if (columna == 0){
                printf(" x\n");
            }
            else{
                printf(" ");
            }
        }
    }
}

int main(){
    dibujoCuadrado(4);
}