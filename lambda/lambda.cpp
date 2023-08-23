// lambda.cpp : example of using a lambda to calculate an annuity
//

#include <iostream>
#include <vector>
#include <numeric>

int main()
{
	std::vector<double> times;
	std::iota(times.begin(), times.end(), 1);
	double PMT = 1000.0;
	double r = 0.05;

	double total_ann = std::accumulate(times.begin(), times.end(), 0.0, [PMT, r](const double& acc, const double& x) {
		return acc + (PMT * (1 - std::pow(1 + r, -x)) / r);
		});

	std::cout << total_ann << std::endl;
}
