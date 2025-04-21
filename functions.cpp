#include <iomanip>

using namespace std;
#include "functions.h"

double** creation(int n, int m) {
    double** A = new double* [n];
    A[0] = new double[n * m];
    for (int i = 1; i < n; i++) {
        A[i] = A[0] + i * m;
    }
    return A;
}
