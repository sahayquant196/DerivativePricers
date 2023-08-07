// Monte Carlo implementation of Black-Scholes price of a European Call
//requires random.cpp
#include "random.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
//Main function
int main()
{
	cout << "\n ****Start: Monte Carlo European Call****" << endl;
	// Input Parameters
	double T = 1; //maturity
	double K = 100; //strike price
	double S0 = 100; //spot
	double sigma = 0.10; //vol
	double r = 0.05; //rate of interest
	int N = 500; //number of time steps
	int M = 100000; //number of MC simulations
	double S[501];
	double sumpayoff = 0;
	double premium = 0;
	double dt = T / N;

	//Main simulation 

	for (int j = 0; j < M; j++)
	{
		S[0] = S0; //initialize each path for MC simulation

		for (int k = 0; k < N; k++)
		{
			double epsilon = SampleBoxMuller(); //draw a Gaussian random variable
			S[k + 1] = S[k] * (1 + r * dt + sigma * sqrt(dt) * epsilon);
		}

		sumpayoff += S[N] - K > 0 ? S[N] - K : 0;
	}

	//Discounted payoff
	premium = exp(-r * T) * (sumpayoff / M);
	//Output results
	cout << "Premium = " << premium << endl;
	cout << "*** END OF RESULT ***" << endl;

	return 0;
}


















































































































































































