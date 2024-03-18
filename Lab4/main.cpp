#include "Sort.h"
#include <stdio.h>

int main() {
    Sort Interval(10, 4, 20);
    Interval.InsertSort();
    Interval.Print();

    int x[] = {1, 2, 3, 4, 5};
    Sort InitializationList = {x, 5};
    InitializationList.Print();

    int v[] = {1, 2, 5, 4, 7, 3, 6};
    Sort Vector(v, 7);
    Vector.BubbleSort(true);
    Vector.Print();

    Sort Variadic(5, 1, 4, 2, 3, 5);
    Variadic.Print();

    Sort String = "10,30,20,15,10,75";
    String.QuickSort(true);
    String.Print();

    printf("Dimensiunea vectorului este: %d\n", String.GetElementsCount());
    printf("Elementul de la pozitia 4 este: %d\n", String.GetElementFromIndex(4));

    return 0;
}