#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// removeDuplicates es una funcion que devuelve la cantidad de valores no repetidos de un array
// [1,1,1,2,2,3,3,3,4,4,5,6]  === [1,2,3,4,5,6] === 6
int removeDuplicates(int arr[], int largo){
    int comp = arr[0];
    int contador = 0;

    for (int i = 0; i <= largo ; i++){
        if (arr[i] == comp){
            comp = arr[i];
        }
        else{
            contador++;
            comp = arr[i];
        }
    }

    return contador;
}


int factorial(int num){
    
    if (num == 0){
        return 1;
    }

    else{

        return num * factorial(num - 1);
    }
}


int main(){

//    int array[] = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 6};
//    printf("%d\n", removeDuplicates(array, 12));

printf("%d\n", factorial(5));
}
