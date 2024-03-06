#include "NumberList.h"

void NumberList::Init() { count = 0; }

bool NumberList::Add(int x) {
    if (count >= 10) return false;

    numbers[count++] = x;
    return true;
}

void NumberList::Sort() {
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
}

void NumberList::Print() {
    for (int i = 0; i < count; i++)
        printf("%d ", numbers[i]);
}