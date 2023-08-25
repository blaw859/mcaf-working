// functional-programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>j
#include <algorithm>
#include <numeric>

template<class F1, class F2=F1>
auto compose(const F1& f, const F2& g) {
    return [=](const auto& x) {return f(g(x)); };
}

std::vector<unsigned> generate_vec(const unsigned n) {
    std::vector<unsigned> result(n);
    std::generate(result.begin(), result.end(), [counter = 0]() mutable {return counter++; });
    return result;
}

template <class T>
T accumulate_vec(const std::vector<T>& v) {
    return std::accumulate(v.begin(), v.end(), T());
}

int main()
{
    // need to specify types input to exp and sqrt, otherwise the compiler wouldn't be able to deduce a type - too many options for overloaded functions
    auto f = compose([](const double x) { return exp(x);  },
        [](const double x) { return sqrt(x); });
    std::cout << f(0.5) << std::endl;
}
