#include <iostream>
#define N 1000
using namespace std;

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    double mul1[i][k];
    double res[i][j];
    double mul2[j][i];
    double tmp[N][N];

    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            tmp[i][j] = mul2[j][i];
            for (i = 0; i < N; ++i)
                for (j = 0; j < N; ++j)
                    for (k = 0; k < N; ++k)
                        res[i][j] += mul1[i][k] * tmp[j][k];

}

