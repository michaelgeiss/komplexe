#include <iostream>
#define N 1000

using namespace std;

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    double res[i][j];
    double mul1[i][k];
    double mul2[k][j];
    //initialisere matrix elemente res mul1 und mul2
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            for (k = 0; k < N; ++k)
    res[i][j] += mul1[i][k] * mul2[k][j];

}

