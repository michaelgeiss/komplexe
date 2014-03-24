#include <iostream>
#include <unistd.h>
#define N 1000
#define SM (sysconf(_SC_LEVEL1_DCACHE_LINESIZE) / sizeof (double))

using namespace std;

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int i2 = 0;
    int j2 = 0;
    int k2 = 0;
    double* rres;
    double* rmul1;
    double* rmul2;
    double res[i][j];
    double mul1[i][k];
    double mul2[k][j];

    for (i = 0; i < N; i += SM)
        for (j = 0; j < N; j += SM)
            for (k = 0; k < N; k += SM)
                for (i2 = 0, rres = &res[i][j],
                    rmul1 = &mul1[i][k]; i2 < SM;
                    ++i2, rres += N, rmul1 += N)
                    for (k2 = 0, rmul2 = &mul2[k][j];
                        k2 < SM; ++k2, rmul2 += N)
                        for (j2 = 0; j2 < SM; ++j2)
                            rres[j2] += rmul1[k2] * rmul2[j2];
}



