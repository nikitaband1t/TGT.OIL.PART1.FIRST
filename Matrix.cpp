//
// Created by bandit on 4/11/16.
//

#include "Matrix.h"


Matrix::Matrix() {
    horizontal_l = 0;
    vertical_l = 0;
}


double Matrix::get_at(int _x, int _y) {
    return (matrix.find(std::pair<int,int>(_x,_y))).operator*().second;
}


double Matrix::insert(int _x, int _y, double value) {
    matrix.insert(std::pair<std::pair<int,int>,double>(std::pair<int,int>(_x,_y),value));
    if (horizontal_l < _x)
        horizontal_l = _x+1;
    if (vertical_l < _y)
        vertical_l = _y+1;
}




Matrix Matrix::get_transponent() {
    std::shared_ptr<Matrix> exec_mat(new Matrix());
    for (int _x_ = 0; _x_ < horizontal_l; ++_x_) {
        for (int _y_ = 0; _y_ < vertical_l; ++_y_) {
            exec_mat.get()->insert(_y_, _x_,
                                   (get_at(_y_,_x_)));
        }
    }
    return *exec_mat.get();
}


Matrix Matrix::operator*(Matrix &matr_arg) {
    std::shared_ptr<Matrix> exec_mat(new Matrix());
    if (horizontal_l == matr_arg.vertical_l) {
        for (int _first_ = 0; _first_ <= vertical_l; ++_first_) {
            for (int _second_ = 0; _second_ <= matr_arg.horizontal_l; ++_second_) {
                double data = 0;
                for (int _itterate_ = 0; _itterate_ <= horizontal_l; ++_itterate_) {
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

double Matrix::determinant(int _k_) {
    if (horizontal_l == 1) {
        return get_at(0, 0);
    }
    else if (horizontal_l == 2) {
        return get_at(0, 0) * get_at(1, 1) - get_at(1, 0) * get_at(0, 1);
    }
    else {
        double determ = 0;
        for (int _x_ = 1; _x_ <= horizontal_l; ++_x_) {
            std::shared_ptr<Matrix> exec_matrix(new Matrix());
            for (int horizont = 0; horizont <= horizontal_l; ++horizont) {
                for (int vert = 0; vert <= horizontal_l; ++vert) {
                    if (horizont != 1 && vert != _x_) {
                        exec_matrix.get()->insert(horizont, vert, get_at(horizont, vert));
                    }
                }
            }
            determ += pow((-1), (1 + _x_)) * exec_matrix.get()->determinant(_k_ - 1);
        }
        return determ;

    }
}

/*Sylvester criteria
 * Count n minors and check that they are non-negative*/

/*Matrix symmetric proved by many ways
 * chosed method is criteria of Sylvester*/
bool Matrix::is_symmetric() {
    for (int _itt_ = 0; _itt_ <= horizontal_l; ++_itt_) {
        if (determinant(_itt_) < 0)
            return false;
    }
    return true;
}

Matrix Matrix::operator+(Matrix &matr) {
    std::shared_ptr<Matrix> exec_mat(new Matrix());
    for (int _x_ = 0; _x_ <=horizontal_l; ++_x_) {
        for (int _y_ = 0; _y_ <=vertical_l; ++_y_) {
            exec_mat.get()->insert(_x_, _y_, get_at(_x_, _y_) + matr.get_at(_x_, _y_));
        }
    }
    return *exec_mat.get();
}

Matrix Matrix::operator-(Matrix matr) {
    std::shared_ptr<Matrix> exec_mat(new Matrix());
    for (int _x_ = 0; _x_ <= horizontal_l; ++_x_) {
        for (int _y_ = 0; _y_ <= vertical_l; ++_y_) {
            exec_mat.get()->insert(_x_, _y_, get_at(_x_, _y_) - matr.get_at(_x_, _y_));
        }
    }
    return *exec_mat.get();
}

Matrix Matrix::operator*(double t) {
    std::shared_ptr<Matrix> exec_mat(new Matrix());
    for (int _x_ = 0; _x_ <= horizontal_l; ++_x_) {
        for (int _y_ = 0; _y_ <= vertical_l; ++_y_) {
            exec_mat.get()->insert(_x_, _y_, get_at(_x_, _y_) * t);
        }
    }
    return *exec_mat.get();
}

void Matrix::represent() {

    for (int i = 0; i <= horizontal_l; ++i) {
        for (int j = 0; j <= vertical_l; ++j) {

            printf("%f ",get_at(i,j));
        }
        printf("\n");
    }
}