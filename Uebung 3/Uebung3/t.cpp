/*#include <iostream>
#include <time.h>
#include <algorithm>
#include <ctime>
#include <stdint.h>

using namespace std;
class MatrixM {


public:
    void getMatrix1(double **mul1, double **mul2, double **res){
        int N = 1000;
        res = new double *[N];

        for(int i = 0; i<N; i++)
        {
            res[i] = new double[N];
        }

        for (int i =  0; i <  N;  ++i)
            for (int j =  0; j <  N;  ++j)
                for (int k =  0; k  <  N;  ++k)
                    res[i][j] +=  mul1[i][k]
                            * mul2[k][j];
    }

    void getMatrix2(double **mul1, double **mul2, double **res){
        int N = 1000;
        double **tmp = new double *[N];
        res = new double *[N];

        for(int i = 0; i<N; i++)
        {
            tmp[i] = new double[N];
            res[i] = new double[N];
        }

        for (int i =  0; i <  N;  ++i)
            for (int j =  0; j <  N;  ++j)
                tmp[i][j] =  mul2[j][i];
        for (int i =  0; i <  N;  ++i)
            for (int j =  0; j <  N;  ++j)
                for (int k =  0; k  <  N;  ++k){
                    int t = mul1[i][k] * tmp[j][k];
                    res[i][j] +=  t;
                }

    }

    double** randomMatrix(){
        int x = 1000, y = 1000;
        double **ptr = new double *[x];
        for(int i = 0; i<y; i++)
        {
            ptr[i] = new double[y];
        }
        srand(time(0));
        for(int j = 0; j<x; j++)
        {
            for(int k = 0; k<y; k++)
            {
                int a = rand()%10;
                ptr[j][k] = a;
            }
        }
        return ptr;
    }
};
int main()
{
    MatrixM m;
    double **m1,**m2,**res;
    time_t t;
    struct timespec requestStart, requestEnd;
#define BILLION 1E9

    time(&t);

    m1 = m.randomMatrix();
    m2 = m.randomMatrix();

    //Matrix method 1
    cout << "Original:" << endl;
    clock_gettime(CLOCK_REALTIME, &requestStart);
    m.getMatrix1(m1,m1,res);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
            + ( requestEnd.tv_nsec - requestStart.tv_nsec )
            / BILLION;
    cout << accum << endl;

    //Matrix method 2
    cout << "Transponed:" << endl;
    clock_gettime(CLOCK_REALTIME, &requestStart);
    m.getMatrix2(m1,m1,res);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = ( requestEnd.tv_sec - requestStart.tv_sec )
            + ( requestEnd.tv_nsec - requestStart.tv_nsec )
            / BILLION;
    cout << accum << endl;

    return 0;
}
*/
