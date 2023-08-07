//for generating Gaussian random numbers using Box Muller method
#include "random.h"
#include <cmath>
using namespace std;

double SampleBoxMuller()
{
	double result;
	double x;
	double y;

	double xysquare;
	do
	{
		x = 2 * rand() / static_cast<double>(RAND_MAX) - 1;
		y = 2 * rand() / static_cast<double>(RAND_MAX) - 1;
		xysquare = x * x + y * y;

	} while
		(xysquare >= 1);
	result = x * sqrt(-2 * log(xysquare) / xysquare);
	return result;
}