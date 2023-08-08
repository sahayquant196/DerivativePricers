//Pricing equity basket options
#include "random.h"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    cout<<"**** MC simulation for equity basket option***"<<endl;
    //Input Parameters
    double T=1; //maturity
    double r=0.05; //rate of interest
    double S10 = 100; //equity 1 spot
    double S20 = 200; //equity 2 spot
    double sigma1 = 0.10; //equity1 vol
    double sigma2 = 0.15; //equity2 vol
    double rho = -0.3; //correlation
    int N = 500; //Time steps
    int M = 10000; //MC simulations
    double S1[N+1];
    double S2[N+1];
    double sumpayoff = 0;
    double premium = 0;
    double dt = T/N;
    //Begin simulation
    for (int i =0;i<M;i++)
    {
        S1[0] = S10;
        S2[0] = S20;
        
        for (int j=0;j<N;j++)
        {
            double ind_epsilon1 = SampleBoxMuller();
            double ind_epsilon2 = SampleBoxMuller();
            S1[j+1] = S1[j]*(1+r*dt+sigma1*sqrt(dt)*ind_epsilon1);
            double epsilon2 = ind_epsilon1*rho + sqrt(1-rho*rho)*ind_epsilon2;
            S2[j+1] = S2[j]*(1+r*dt+sigma2*sqrt(dt)*epsilon2);
            
            
            
        }
        
        //cout<<"S1[N]"<<S1[N]<<endl;
        //cout<<"S2[N]"<<S2[N]<<endl;
        sumpayoff += max(S1[N], S2[N]);

    }
    
        premium = exp(-r*T)*(sumpayoff/M);
        //Output
        cout<<"*** Premium "<<premium<<endl;
        cout<<"***END OF CALCULATION***"<<endl;
}