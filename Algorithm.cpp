//
// Created by bandit on 4/7/16.
//
#include "Algorithm.h"
#include <iostream>
void Algo::Gradient() {

}
Matrix &Algo::get_matrix() {
    std::cout<<"Write down capacity system of linear equations:"<<std::endl;
    int capacity;
    std::cin>>capacity;
    std::shared_ptr<Matrix<double>> matrix(new Matrix<double>());
    for(int j = 0; j< capacity; ++j){
        for(int i = 0; i< capacity ; ++i){
            double data;
            std::cin>>data;
            matrix.get()->insert(i,j,data);
        }
    }
}

void Algo::gradient_algorithm(double x0) {
    Matrix matrix = get_matrix();
    if(matrix.is_symmetric()){
       Matrix argv = get_arguments();
       Matrix args = fill_matrix();
       Matrix gradient = argv - matrix*fill_matrix();
       Matrix approximation =  gradient;
       int capacity = 0;
        start_algorithm(&gradient,&approximation,capacity,matrix);
    }
    else{
        std::cout<<"Algorithm could'not be explored, matrix does'not non-negative symmetric";
    }
}

Matrix &Algo::get_arguments() {
    std::cout<<"Write down capacity system of linear equations:"<<std::endl;
    int capcity;
    std::cin>>capcity;
    std::shared_ptr<Matrix<double>> matrix(new Matrix<double>());
    for(int j = 0;j< capcity; ++j){
        double  data;
        std::cin>>data;
        matrix.get()->insert(0,j,data);
    }
}
double Algo::scalar_mul(Matrix & fst, Matrix & snd) {

}

Matrix &Algo::start_algorithm(Matrix *gradient, Matrix *approximation, int &capacity,Matrix coeff) {
   if(capacity!=0) {
       double help_arg_approx = scalar_mul(*gradient, *gradient)
                                / scalar_mul(coeff * (*gradient), *gradient);

       Matrix curr_gradient = *gradient - (coeff) * help_arg_approx * (*approximation);

       double help_arg_build_approx = scalar_mul(curr_gradient, curr_gradient)
                                      / scalar_mul(*gradient, *gradient);

       Matrix new_approx = *gradient - (*approximation) * help_arg_build_approx;

       capacity--;
       return start_algorithm(&curr_gradient,&new_approx,capacity,coeff);
   }
    else
       return  *(new Matrix());
}