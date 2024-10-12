#include <armadillo>
#include <iostream>
#include <cassert>

int main()
{
    arma::mat coefficient_matrix = {{3, 2}, {-1, 1}};
    arma::vec constant_vector = {7, 6};

    arma::vec result_vector = arma::solve(coefficient_matrix, constant_vector);

    const double x1 = result_vector(0);
    const double x2 = result_vector(1);
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;

    assert(x1 == -1);
    assert(x2 == 5);

    return 0;
}
