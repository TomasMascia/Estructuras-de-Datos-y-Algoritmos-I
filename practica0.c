#include <stdio.h>
#include <stdlib.h>


// 1-
int direc_memoria(){
    int array[] = {1,2,3,4,5};
    for(int i = 0; i < 5; i++){
    printf("variable: %d\n direccion: 0x%p\n", array[i], &array[i]);}
}


// 2-
void set_first(int array[]){
    array[0] = 0;
}


// 3-
void set_in(int *puntero){
    if (*puntero != 0 ){
        printf("cambiamos %d a ", *puntero);
        *puntero = 0;
        printf("%d \n", *puntero);
    }
    else{
        printf("no realizamos cambios %d \n", *puntero);
    }
}


// 4-
void swap(int *punt1 , int *punt2){
    printf("La variable %d esta en la memoria de %p \n", *punt1 , punt1);
    printf("La variable %d esta en la memoria de %p \n", *punt2 , punt2);

    int copie = *punt1;
    *punt1 = *punt2;
    *punt2 = copie;

    printf("La variable %d esta en la memoria de %p \n", *punt1 , punt1);
    printf("La variable %d esta en la memoria de %p \n", *punt2 , punt2);

}


// 6-
int capacity = 10;
char *get_new_line(void){
void *punt = malloc(sizeof(char) * capacity);

if (sizeof(*punt) >= capacity){
    
}

}


// 7-
void mallocfree(){
    int *punt = malloc(sizeof(int) * 10000);

    free(punt);
    free(punt);
}
// double free or corruption (top)




int main(){
// 1
//    direc_memoria();


// 2
// int lista1[] = {22,2,3,4,5,6};
// printf("%d\n", lista1[0]);
// set_first(lista1);
// printf("%d\n", lista1[0]);


// 3
// int num1 = 6;
// int *punterito = &num1;
// set_in(punterito);


// 4
// int val1 = 3;
// int val2 = 5;
// int *dic1 = &val1;
// int *dic2 = &val2;
// swap(dic1, dic2);


// 6


// 7
//mallocfree();
//
//    return 0;
//}

// 8
