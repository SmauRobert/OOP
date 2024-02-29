#include "header.h"

int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; } 

int main(int argc, char* argv[])
{
    char input[38] = "---H***E+++L+++L///O---P+++O/+-**O---"; 
    func Operatori[4] = {Sum, Dif, Mul, Div};
    int S = 0, V = strlen(input);
    Content x;
    int idx;

    for (int i = 0; i < V; i++)
    {
        switch (input[i] - 42)
        {
            case INMULTIRE: // + 9
                idx = 2;
                x.p1 = 3;
                x.p2 = 3;
                break;
            case SUMA:      // + 12
                idx = 0;
                x.p1 = 7;
                x.p2 = 5;
                break;
            case DIFERENTA: // + 9
                idx = 1;
                x.p1 = 10;
                x.p2 = 1;
                break;
            case IMPARTIRE: // + 2
                idx = 3;
                x.p1 = 8;
                x.p2 = 4;
                break;
        }

        S = S + Operatori[idx](x.p1, x.p2);
    }

    //S=337
    printf("S = %d\n", S);

    return 0;
}
