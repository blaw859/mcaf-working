#include <cstdlib>
#include <ctime>
#include <iostream>

#include "matrix.h"

void MatrixProductNaive(
	const matrix<double> &a,
	const matrix<double> &b,
	matrix<double> &c) {
	const size_t rows = a.rows(), cols = b.cols(), n = a.cols();

	for (size_t i = 0; i < rows; ++i) {
		const auto ai = a[i];
		auto ci = c[i];

		for (size_t j = 0; j < cols; ++j) {
			double res = 0.0;
			for (size_t k = 0; k < n; ++k) {
				res += ai[k] * b[k][j];
			}

			c[i][j] = res;
		}
	}
}

void MatrixProductImproved(
	const matrix<double>& a,
	const matrix<double>& b,
	matrix<double>& c) {
	const size_t rows = a.rows(), cols = b.cols(), n = a.cols();

	for (size_t i = 0; i < rows; ++i) {
		auto ci = c[i];
		for (size_t j = 0; j < cols; ++j) {
			ci[j] = 0;
		}
	}
	
#pragma omp parallel for
	for (int i = 0; i < rows; ++i) {
		const auto ai = a[i];
		auto ci = c[i];

		// now loop on dot product instead of columns
		for (size_t k = 0; k < n; ++k) {
			const auto bk = b[k];

			// this prevents the jump on the innermost loop
			const auto aik = ai[k];

			for (size_t j = 0; j < cols; ++j) {
				ci[j] += aik * bk[j];
			}
		}
	}
}



void PopulateRandomMatrix(size_t size, matrix<double>& m) { // TODO: doesn't need size at all
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(nullptr));
		seeded = true;
	}

	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			// Generate a random double between 0 and 1
			double value = static_cast<double>(rand()) / RAND_MAX;
			m[i][j] = value;
		}
	}
}
