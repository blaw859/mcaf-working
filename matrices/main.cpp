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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
