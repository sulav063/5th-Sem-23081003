//In a single pump service station, vehicles arrive for fueling with an average of 5 minutes between arrivals. 
//If an hour is taken as unit of time, cars arrive according to Poison’s process with an average of ?= 12 cars/hr.
//Write a C program to generate Poisson distribution for x = 0,1,2, …. 15.
#include <stdio.h>
#include <math.h>

// Function to calculate factorial manually
long double factorial(int n) {
    long double fact = 1.0;
    int i;  // Declare loop variable outside the loop
    for (i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Poisson distribution function
double poisson(int x, double lambda) {
    return (exp(-lambda) * pow(lambda, x)) / factorial(x);
}

int main() {
    float lambda;  // Use float for compatibility
    int x;  // Declare loop variable here

    // Prompt user for input
    printf("Enter the average arrival rate (lambda): ");
    if (scanf("%f", &lambda) != 1 || lambda <= 0) {  
        printf("Invalid input. Lambda must be a positive number.\n");
        return 1;
    }

    // Display results
    printf("\nPoisson Distribution for x = 0 to 15 (lambda = %.2f):\n", lambda);
    printf("-------------------------------------------------\n");

    for (x = 0; x <= 15; x++) {  // Declare 'x' outside the loop
        double probability = poisson(x, lambda);
        printf("P(X = %2d) = %.6f\n", x, probability);
    }

    return 0;
}



