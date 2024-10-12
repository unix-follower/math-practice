#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <cassert>

namespace ublas = boost::numeric::ublas;

const unsigned short FIRST_INDEX = 0;
const unsigned short SECOND_INDEX = 1;
const unsigned short THIRD_INDEX = 2;

const unsigned short FIRST_ROW = FIRST_INDEX;
const unsigned short SECOND_ROW = SECOND_INDEX;
const unsigned short THIRD_ROW = THIRD_INDEX;

const unsigned short FIRST_COLUMN = FIRST_INDEX;
const unsigned short SECOND_COLUMN = SECOND_INDEX;
const unsigned short THIRD_COLUMN = THIRD_INDEX;

int main()
{
  ublas::matrix<double> coefficient_matrix(3, 3);
  coefficient_matrix(FIRST_ROW, FIRST_COLUMN) = 3;
  coefficient_matrix(FIRST_ROW, SECOND_COLUMN) = 0;
  coefficient_matrix(FIRST_ROW, THIRD_COLUMN) = 0;
  coefficient_matrix(SECOND_ROW, FIRST_COLUMN) = 1;
  coefficient_matrix(SECOND_ROW, SECOND_COLUMN) = 5;
  coefficient_matrix(SECOND_ROW, THIRD_COLUMN) = -2;
  coefficient_matrix(THIRD_ROW, FIRST_COLUMN) = 1 / 3.0;
  coefficient_matrix(THIRD_ROW, SECOND_COLUMN) = 2;
  coefficient_matrix(THIRD_ROW, THIRD_COLUMN) = 0;

  ublas::vector<double> constant_vector(3);
  constant_vector(FIRST_COLUMN) = 9;
  constant_vector(SECOND_COLUMN) = 2;
  constant_vector(THIRD_COLUMN) = 3;

  ublas::permutation_matrix<std::size_t> pm(coefficient_matrix.size1());
  ublas::lu_factorize(coefficient_matrix, pm);
  ublas::lu_substitute(coefficient_matrix, pm, constant_vector);

  const double x1 = constant_vector(FIRST_COLUMN);
  const double x2 = constant_vector(SECOND_COLUMN);
  const double x3 = constant_vector(THIRD_COLUMN);
  std::cout << "x1 = " << x1 << std::endl;
  std::cout << "x2 = " << x2 << std::endl;
  std::cout << "x3 = " << x3 << std::endl;

  assert(static_cast<int>(round(x1)) == 3);
  assert(static_cast<int>(round(x2)) == 1);
  assert(static_cast<int>(round(x3)) == 3);

  return 0;
}
