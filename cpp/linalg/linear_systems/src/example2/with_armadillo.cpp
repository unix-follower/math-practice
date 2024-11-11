#include "../constants.hpp"

#include <armadillo>
#include <iostream>
#include <cassert>

int main()
{
    arma::mat coefficient_matrix = {
        {3.0, 0.0, 0.0},
        {1.0, 5.0, -2.0},
        {1.0 / 3.0, 2.0, 0.0}};

    arma::vec constant_vector = {9.0, 2.0, 3.0};

    arma::vec result_vector = arma::solve(coefficient_matrix, constant_vector);

    const double x1 = result_vector(FIRST_COLUMN);
    const double x2 = result_vector(SECOND_COLUMN);
    const double x3 = result_vector(THIRD_COLUMN);
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
    std::cout << "x3 = " << x3 << std::endl;

    assert(static_cast<int>(round(x1)) == 3);
    assert(static_cast<int>(round(x2)) == 1);
    assert(static_cast<int>(round(x3)) == 3);

    return 0;
}
