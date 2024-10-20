#include "../constants.hpp"

#include <armadillo>
#include <iostream>
#include <cassert>

int main()
{
    arma::mat coefficient_matrix = {
        {1.0, 1.0, 0.0},
        {2.0, -1.0, 3.0},
        {1.0, -2.0, -1.0}};

    arma::vec constant_vector = {0.0, 3.0, 3.0};

    arma::vec result_vector = arma::solve(coefficient_matrix, constant_vector);

    const double x = result_vector(FIRST_COLUMN);
    const double y = result_vector(SECOND_COLUMN);
    const double z = result_vector(THIRD_COLUMN);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;

    assert(static_cast<int>(round(x)) == 1);
    assert(static_cast<int>(round(y)) == -1);
    assert(static_cast<int>(round(z)) == 0);

    return 0;
}
