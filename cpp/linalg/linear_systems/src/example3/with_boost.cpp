#include "../constants.hpp"

#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ublas = boost::numeric::ublas;

template <typename T>
bool lu_solve(ublas::matrix<T> &A, ublas::vector<T> &b, ublas::vector<T> &x)
{
  ublas::permutation_matrix<std::size_t> pm(A.size1());
  bool is_singular_matrix = ublas::lu_factorize(A, pm);
  if (is_singular_matrix)
  {
    return false;
  }
  x.assign(b);
  ublas::lu_substitute(A, pm, x);
  return true;
}

int main()
{
  ublas::matrix<double> coefficient_matrix(3, 3);
  coefficient_matrix(FIRST_ROW, FIRST_COLUMN) = 1;
  coefficient_matrix(FIRST_ROW, SECOND_COLUMN) = 1;
  coefficient_matrix(FIRST_ROW, THIRD_COLUMN) = 0;
  coefficient_matrix(SECOND_ROW, FIRST_COLUMN) = 2;
  coefficient_matrix(SECOND_ROW, SECOND_COLUMN) = -1;
  coefficient_matrix(SECOND_ROW, THIRD_COLUMN) = 3;
  coefficient_matrix(THIRD_ROW, FIRST_COLUMN) = 1;
  coefficient_matrix(THIRD_ROW, SECOND_COLUMN) = -2;
  coefficient_matrix(THIRD_ROW, THIRD_COLUMN) = -1;

  ublas::vector<double> constant_vector(3);
  constant_vector(FIRST_COLUMN) = 0;
  constant_vector(SECOND_COLUMN) = 3;
  constant_vector(THIRD_COLUMN) = 3;

  ublas::vector<double> result_vector(3);

  bool can_solve = lu_solve(coefficient_matrix, constant_vector, result_vector);
  if (!can_solve)
  {
    std::cerr << "The matrix is singular and cannot be solved." << std::endl;
    return -1;
  }

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
