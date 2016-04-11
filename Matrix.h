//
// Created by bandit on 4/7/16.
//

#ifndef FIRST_MATRIX_H
#define FIRST_MATRIX_H

#include <map>
#include <math.h>
#include <memory>

class Matrix {
    std::map<std::pair<int, int>, double> matrix;
    int horizontal_l, vertical_l;
public:
    Matrix();

    double insert(int _x, int _y, double value);

    Matrix get_transponent();

    Matrix operator*(Matrix &);

    Matrix operator-(Matrix);


    Matrix operator+(Matrix &);

    Matrix operator*(double t);

    bool operator==(Matrix &);

    double get_at(int _x, int _y);

    double determinant(int _k_);

    bool is_symmetric();

    double get_horizontal() { return horizontal_l; }

    double get_vertical() { return vertical_l; }

    void represent();
};


#endif //FIRST_MATRIX_H
