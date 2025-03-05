//In a single pump service station, vehicles arrive for fueling with an average of 5 minutes between arrivals. 
//If an hour is taken as unit of time, cars arrive according to Poison’s process with an average of ?= 12 cars/hr.
//Write a C program to generate Poisson distribution for x = 0,1,2, …. 15.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double poisson(int x, double lambda) {
    return exp(-lambda) * pow(lambda, x) / tgamma(x + 1);
}
int main() {
    double lambda;   
    // Prompt user for input
    printf("Enter the average arrival rate (lambda): ");
    if (scanf("%lf", &lambda) != 1 || lambda <= 0) {
        printf("Invalid input. Lambda must be a positive number.\n");
        return 1;
    }
    printf("\nPoisson Distribution for x = 0 to 15:\n", lambda);
    printf("-------------------------------------------------\n");
    for (int x = 0; x <= 15; x++) {
        double probability = poisson(x, lambda);
        printf("P(X = %2d) = %.6f\n", x, probability);
    }
    return 0;
}

