#include "Sort.h"
#include <stdarg.h>
#include <stdio.h>
#include <random>
#include <ctime>

Sort::Sort(int count, int minValue, int maxValue) {
    this->list = new int[count];
    this->size = count;

    srand(time(NULL));
    for(int i = 0; i < count; i ++)
        this->list[i] = minValue + rand() % (maxValue - minValue);
}

Sort::Sort(int *vector, int count) {
    this->list = new int[count];
    this->size = count;
    for(int i = 0; i < count; i ++)
        this->list[i] = vector[i];
}

Sort::Sort(int count, ...) {
    this->list = new int[count];
    this->size = count;

    va_list Nums;
    va_start(Nums, count);
    for(int i = 0; i < count; i ++)
        this->list[i] = va_arg(Nums, int);
    va_end(Nums);
}

Sort::Sort(const char *str) {
    this->size = 1;
    for(int i = 0; str[i]; i ++)
        if(str[i] == ',') this->size ++;

    this->list = new int[this->size];

    int num = 0, index = 0;
    for(int i = 0; str[i]; i ++)
        if(str[i] == ',') {
            list[index ++] = num;
            num = 0;
        } else num = num * 10 + str[i] - '0';
        
    list[index ++] = num;
}

void Sort::InsertSort(bool ascendent) {
    for(int i = 0; i < this->size; i ++) {
        int index = i;
        while(index > 0 && (this->list[index] > this->list[index - 1]) != ascendent) {
            int temp = this->list[index];
            this->list[index] = this->list[index - 1];
            this->list[index - 1] = temp;

            index --;  
        }
    }
}

void Sort::QuickSort(bool ascendent) {
    QS(0, this->size - 1, ascendent);
}

void Sort::QS(int left, int right, bool ascendent) {
    if(left >= right) return;

    int el = this->list[left + rand() % (right - left + 1)];
    
    int temp = this->list[left];
    this->list[left] = el;
    el = temp;

    int i = left + 1, j = right;

    while(i <= j) {
        while((this->list[i] <= el) == ascendent)
            i ++;
        while((this->list[j] >= el) == ascendent)
            j --;

        if(i < j && (this->list[i] < el) != ascendent && (this->list[j] > el) != ascendent) {
            int temp = this->list[i];
            this->list[i] = this->list[j];
            this->list[j] = temp;

            i ++;
            j --;
        }
    }

    this->list[left] = this->list[i - 1];
    this->list[i - 1] = el;

    QS(left, i - 2, ascendent);
    QS(i, right, ascendent);
}

void Sort::BubbleSort(bool ascendent) {
    bool swaps = true;
    while(swaps) {
        swaps = false;
        for(int i = 0; i < this->size - 1; i ++)
            if((this->list[i] < this->list[i + 1]) != ascendent) {
                int temp = this->list[i];
                this->list[i] = this->list[i + 1];
                this->list[i + 1] = temp;

                swaps = true;
            }
    }
}

void Sort::Print() {
    for(int i = 0; i < this->size; i ++)
        printf("%d ", list[i]);
    printf("\n");
}

int Sort::GetElementsCount() { return size; }

int Sort::GetElementFromIndex(int index) { return list[index]; }
