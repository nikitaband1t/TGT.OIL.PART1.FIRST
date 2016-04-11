//
// Created by bandit on 4/7/16.
//
#include "Matrix.h"

namespace Algo {
    void gradient_algorithm(double x0);

    void Gradient();


    Matrix &get_matrix(int capacity);


    Matrix &get_eqval(int capacity);


    Matrix &fill_matrix();


    Matrix &start_algorithm(Matrix *gradient, Matrix *approximation, int &capacity, Matrix coeff);

    double scalar_mul_for_grad(Matrix , Matrix &);
};

