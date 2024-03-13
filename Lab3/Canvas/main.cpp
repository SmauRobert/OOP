#include <iostream>
#include "Canvas.h"

using namespace std;

int main() {
    int W = 36, H = 18;
    Canvas C(W, H);
    C.Clear();
    C.DrawRect(0, 0, W - 1, H - 1, '#');
    C.FillRect(1, 1, W - 2, H - 2, '.');

    char text[] = "I made this!"; 
    int lg = 12, stroke = 2;

    for(int i = 0; i < lg; i ++)
        C.SetPoint(W / 2 - lg / 2 + i, H / 2, text[i]);

    C.DrawCircle(W / 2, H / 4, 3, 'O');
    C.FillCircle(W / 2, H / 4 * 3 + 1, 3, ' ');

    C.DrawLine(1, H - 2, W / 2 - 3, H / 2 + 2, '/');

    C.Print();

    return 0;
}