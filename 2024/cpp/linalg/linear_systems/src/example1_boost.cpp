#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <iostream>
#include <cassert>

int main()
{
    using namespace boost::numeric::ublas;

    matrix<double> coefficient_matrix(2, 2);
    coefficient_matrix(0, 0) = 3;
    coefficient_matrix(0, 1) = 2;
    coefficient_matrix(1, 0) = -1;
    coefficient_matrix(1, 1) = 1;

    vector<double> constant_vector(2);
    constant_vector(0) = 7;
    constant_vector(1) = 6;

    permutation_matrix<std::size_t> perm_matrix(coefficient_matrix.size1());
    int lu_factorize_result = lu_factorize(coefficient_matrix, perm_matrix);
    if (lu_factorize_result != 0)
    {
        std::cerr << "LU factorization failed" << std::endl;
        return -1;
    }

    vector<double> result_vector(constant_vector);
    lu_substitute(coefficient_matrix, perm_matrix, result_vector);

    const double x1 = result_vector(0);
    const double x2 = result_vector(1);
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;

    assert(x1 == -1);
    assert(x2 == 5);

    return 0;
}
