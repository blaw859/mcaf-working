// matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

#include "matrix.h"

int main()
{
    matrix<double> m1(1000, 1000);
    matrix<double> m2(1000, 1000);

    PopulateRandomMatrix(1000, m1);
    PopulateRandomMatrix(1000, m2);

    matrix<double> result(1000, 1000);

    auto start = std::chrono::high_resolution_clock::now();
    MatrixProductNaive(m1, m2, result);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> naive_time_taken = end - start;

    std::cout << "naive approach: " <<  std::fixed << std::setprecision(9) << naive_time_taken << std::endl;

    start = std::chrono::high_resolution_clock::now();
    MatrixProductImproved(m1, m2, result);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> improved_time_taken = end - start;

    std::cout << "improved approach: " <<  std::fixed << std::setprecision(9) << improved_time_taken << std::endl;
}
