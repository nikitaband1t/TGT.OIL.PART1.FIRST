//
// Created by bandit on 4/7/16.
//
#include "Algorithm.h"
#include <iostream>

void Algo::Gradient() {

}

Matrix &Algo::get_matrix(int capacity) {

    std::shared_ptr<Matrix> matrix(new Matrix());
    for (int j = 0; j < capacity; ++j) {
        for (int i = 0; i < capacity; ++i) {
            double data;
            std::cin >> data;
            matrix.get()->insert(i, j, data);
        }
    }
}

void Algo::gradient_algorithm(double x0) {
    int capacity;
    std::cout << "Write down capacity system of linear equations:" << std::endl;
    std::cin >> capacity;

    Matrix coef_matrix = get_matrix(capacity);
    if (coef_matrix.is_symmetric()) {
        Matrix argv = get_eqval(capacity);
        Matrix args = fill_matrix();
        Matrix gradient = argv - coef_matrix * fill_matrix();
        Matrix approximation = gradient;
        start_algorithm(&gradient, &approximation, capacity, coef_matrix);
    }
    else {
        std::cout << "Algorithm could'not be explored, matrix does'not non-negative symmetric";
    }
}

Matrix &Algo::fill_matrix() {

}

/*
 * Scalar for gradient vector*/
double Algo::scalar_mul_for_grad(Matrix &fst, Matrix &snd) {
    double aggr = 0;
    for (int i = 0; i < fst.get_vertical(); ++i) {
        aggr += fst.get_at(0, i) + snd.get_at(0, i);
    }
    return  aggr;
}
/*
 * Get vector of equations result values
 * */
Matrix &Algo::get_eqval(int capacity) {
    std::shared_ptr<Matrix> matrix(new Matrix());
    for (int j = 0; j < capacity; ++j) {
        double data;
        std::cin >> data;
        matrix.get()->insert(0, j, data);
    }
    return *matrix.get();
}

Matrix &Algo::start_algorithm(Matrix *gradient, Matrix *approximation, int &capacity, Matrix coeff) {
    if (capacity != 0) {
        double help_arg_approx = scalar_mul_for_grad(*gradient, *gradient)
                                                     / scalar_mul_for_grad((coeff * (*gradient)), *gradient);

        Matrix curr_gradient = *gradient - (coeff) * help_arg_approx * (*approximation);

        double help_arg_build_approx = scalar_mul_for_grad(curr_gradient, curr_gradient)
                                       / scalar_mul_for_grad(*gradient, *gradient);

        Matrix new_approx = *gradient - (*approximation) * help_arg_build_approx;

        capacity--;
        return start_algorithm(&curr_gradient, &new_approx, capacity, coeff);
    }
    else
        return *(new Matrix());
}