#include "NumberList.h"

int main() {
    NumberList L;
    L.Init();
    for (int i = 0; i <= 12; i++)
        printf("%d\n", L.Add((12 - i + 1) * 8));

    L.Sort();
    L.Print();

    return 0;
}