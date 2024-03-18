#pragma once

class Sort {
    // add data members
    int *list;
    int size;

    void QS(int left, int right, bool ascendent);
public:
    // add constuctors
    Sort(int size, int minValue, int maxValue);
    Sort(int *vector, int size);
    Sort(int count, ...);
    Sort(const char *str);

    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
