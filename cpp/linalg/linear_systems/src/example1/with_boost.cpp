#include "../constants.hpp"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <iostream>
#include <cassert>

int main()
{
    using namespace boost::numeric::ublas;

    matrix<double> coefficient_matrix(2, 2);
    coefficient_matrix(FIRST_ROW, FIRST_COLUMN) = 3;
    coefficient_matrix(FIRST_ROW, SECOND_COLUMN) = 2;
    coefficient_matrix(SECOND_ROW, FIRST_COLUMN) = -1;
    coefficient_matrix(SECOND_ROW, SECOND_COLUMN) = 1;

    vector<double> constant_vector(2);
    constant_vector(FIRST_COLUMN) = 7;
    constant_vector(SECOND_COLUMN) = 6;

    permutation_matrix<std::size_t> perm_matrix(coefficient_matrix.size1());
    int lu_factorize_result = lu_factorize(coefficient_matrix, perm_matrix);
    if (lu_factorize_result != 0)
    {
        std::cerr << "LU factorization failed" << std::endl;
        return -1;
    }

    vector<double> result_vector(constant_vector);
    lu_substitute(coefficient_matrix, perm_matrix, result_vector);

    const double x1 = result_vector(FIRST_COLUMN);
    const double x2 = result_vector(SECOND_COLUMN);
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;

    assert(x1 == -1);
    assert(x2 == 5);

    return 0;
}
