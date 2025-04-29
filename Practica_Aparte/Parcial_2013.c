#include <stdio.h>
#include <stdlib.h>

typedef struct _SOList
{
    int value;
    struct _SOList *next;
} SOList;

SOList *solist_add(int x, SOList *list)
{
    SOList *new_node = malloc(sizeof(SOList));
    new_node->value = x;
    new_node->next = NULL;

    if (list == NULL || x <= list->value)
    {
        new_node->next = list;
        return new_node;
    }

    SOList *current = list;

    while (current->next != NULL && current->next->value < x)
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;

    return list;
}

void solistdestroy(SOList *list)
{
    SOList *temp;
    while (list != NULL)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}

void solistprint(SOList *list)
{
    while (list != NULL)
    {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

void printordered(int arr[], int n)
{
    SOList *list = NULL;
    for (int i = 0; i < n; i++)
    {
        list = solist_add(arr[i], list);
    }
    solistprint(list);
    solistdestroy(list);
}
//__________________________________________________________________________________________

typedef struct _foos{
    int x, y;
} foos;

void foof(foos s){
    s.x = 42; 
    }


void arrf(int a[]){
    a[0] = 42;
}

void f(void){
    foos s = {1, 2};
    int a[] = {1, 2};
    foof(s);
    arrf(a);
    printf("%d %d", s.x, a[0]);
}

int main(){
    f();
}