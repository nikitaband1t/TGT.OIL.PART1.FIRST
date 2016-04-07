//
// Created by bandit on 4/7/16.
//

#ifndef FIRST_MATRIX_H
#define FIRST_MATRIX_H

#include <map>
#include <bits/shared_ptr.h>
#include "Key.h"
#include <math.h>

template<class T>
class Matrix {
    std::map<Key, T> matrix;
    int horizontal_l, vertical_l;
public:
    Matrix();

    T insert(int _x, int _y, T value);

    Matrix &get_transponent();

    Matrix &operator*(Matrix &);

    Matrix &operator-(Matrix &);

    Matrix &operator=(Matrix &);

    Matrix &operator+(Matrix &);
    Matrix &operator*(double t);
    T &get_at(int _x, int _y);

    T determinant(int _k_);

    bool is_symmetric();

};

template<class T>
Matrix<T>::Matrix() {
    horizontal_l = 0;
    vertical_l = 0;
}

template<class T>
T &Matrix<T>::get_at(int _x, int _y) {
    return *matrix.find(*std::shared_ptr<Key>(new Key(_x, _y)).get());
}

template<class T>
T Matrix<T>::insert(int _x, int _y, T value) {
    matrix.insert(new Key(_x, _y), value);
    if (horizontal_l < _x)
        horizontal_l = _x;
    if (vertical_l < _y)
        vertical_l = _y;
}


template<class T>
Matrix<T> &Matrix<T>::get_transponent() {
    std::shared_ptr<Matrix<T>> exec_mat(new Matrix<T>());
    for (int _x_ = 0; _x_ < horizontal_l; ++_x_) {
        for (int _y_ = 0; _y_ < vertical_l; ++_y_) {
            exec_mat.get()->insert(_y_, _x_, matrix.find(*std::shared_ptr<Key>(new Key(_y_, _x_)).get()));
        }
    }
    return *exec_mat.get();
}


template<class T>
Matrix<T> &Matrix<T>::operator*(Matrix &matr_arg) {
    std::shared_ptr<Matrix<T>> exec_mat(new Matrix<T>());
    if (horizontal_l == matr_arg.vertical_l) {
        for (int _first_ = vertical_l; _first_ < vertical_l; ++_first_) {
            for (int _second_ = matr_arg.horizontal_l; _second_ < matr_arg.horizontal_l; ++_second_) {
                T data;
                for (int _itterate_ = horizontal_l; _itterate_ < horizontal_l; ++_itterate_) {
                    data += get_at(_first_, _itterate_) * matr_arg.get_at(_itterate_, _second_);
                }
                exec_mat.get()->insert(_first_, _second_, data);
            }
        }
    }
    return *exec_mat.get();
}

/*Determinate assumption executes by algorithm
 * */
template<class T>
T Matrix<T>::determinant(int _k_) {
    if (horizontal_l == 1) {
        return get_at(0,0);
    }
    else if (horizontal_l == 2) {
        return get_at(0,0)*get_at(1,1)-get_at(1,0)*get_at(0,1);
    }
    else {
        T determ = 0;
        for (int _x_ = 1; _x_ <= horizontal_l; ++_x_) {
            std::shared_ptr<Matrix> exec_matrix(new Matrix());
            for (int horizont = 0; horizont <= horizontal_l; ++horizont) {
                for (int vert = 0; vert <= horizontal_l; ++vert) {
                    if(horizont!=1 && vert!=_x_){
                        exec_matrix.get()->insert(horizont,vert,get_at(horizont,vert));
                    }
                }
            }
            determ += pow((-1), (1 + _x_)) * exec_matrix.get()->determinant(_k_-1);
        }

    }
}

/*Sylvester criteria
 * Count n minors and check that they are non-negative*/
template<class T>
bool Matrix<T>::is_symmetric() {
    for (int _itt_ = 0; _itt_ <= horizontal_l; ++_itt_) {
        if (determinant(_itt_) < 0)
            return false;
    }
    return true;

}

#endif //FIRST_MATRIX_H
