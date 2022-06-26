#include <iostream>
#include "math_tools.h"

using namespace std;

int main()
{
    int dim = 3;
    double *a = new double[dim * dim];
    double *b = new double[dim];
    double *x = new double[dim];

    // initialization of SLAE
    a[0] = 2; a[1] = 5; a[2] = 4;
    a[3] = 1; a[4] = 3; a[5] = 2;
    a[6] = 2; a[7] = 10; a[8] = 9;
    b[0] = 30; b[1] = 150; b[2] = 110;

    // printing
    std::cout << "SLAE with matrix" << std::endl;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("a(%d,%d) = %f, ", i, j, a[dim * i + j]);
        }
        std::cout << std::endl;
    }
    std::cout << "And right-part vector" << std::endl;
    for (int j = 0; j < dim; j++) {
        printf("b(%d) = %f, ", j, b[j]);
    }
    std::cout << std::endl;

    // solving
    int error = MathTools::SlaeSolver::LUP(a, b, x, dim);
    if (!error) {
        std::cout << "Solution of SLAE is" << std::endl;
        for (int j = 0; j < dim; j++) {
            printf("x(%d) = %f, ", j, x[j]);
        }
        std::cout << std::endl;

        return 0;
    } else {
        std::cout << "Smth wrong with SLAE solving!" << std::endl;
        return error;
    }
}
