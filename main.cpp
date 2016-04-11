#include "Matrix.h"
#include <iostream>

int main() {
    Matrix matrix;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix.insert(i,j,1);
        }
    }

    matrix.represent();
    std::cout<<std::endl;
    Matrix temp = matrix*matrix;
    temp.represent();
    return 0;
}