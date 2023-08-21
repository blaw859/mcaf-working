#pragma once
#include <vector>

template <class T>
class matrix {
	// dimensions
	size_t my_rows;
	size_t my_cols;

	// data
	std::vector<T> my_vector;

public:

	using value_type = T;

	// constructors
	matrix() : my_rows(0), my_cols(0) {}
	matrix(const size_t rows, const size_t cols) : my_rows(rows), my_cols(cols), my_vector(rows* cols) {}

	// access
	size_t rows() const { return my_rows; }
	size_t cols() const { return my_cols; }

	// so we can call matrix[i][j]
	T* operator[] (const size_t row) { return &my_vector[row * my_cols]; }

	const T* operator[] (const size_t row) const { return &my_vector[row * my_cols]; }
};

void MatrixProductNaive(const matrix<double>& a, const matrix<double>& b, matrix<double>& c);

void MatrixProductImproved(
	const matrix<double>& a,
	const matrix<double>& b,
	matrix<double>& c);

void PopulateRandomMatrix(size_t size, matrix<double>& m);

template <class T>
void PrintMatrix(const matrix<T>& m) {
	for (size_t i = 0; i < m.rows(); ++i) {
		for (size_t j = 0; j < m.cols(); ++j) {
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
