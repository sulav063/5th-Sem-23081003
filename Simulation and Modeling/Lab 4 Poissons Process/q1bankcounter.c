#include <stdio.h>
int main() {
    double arrival_time, service_time, lambda, mu, rho, P0, L, W;
    printf("Enter the mean inter-arrival time (in minutes): ");
    scanf("%lf", &arrival_time);
    printf("Enter the average service time per customer (in minutes): ");
    scanf("%lf", &service_time);
    lambda = 1.0 / arrival_time;  // Arrival rate (customers per minute)
    mu = 1.0 / service_time;      // Service rate (customers per minute)
    // Check if system is stable (rho < 1)
    if (lambda >= mu) {
        printf("\nSystem is unstable! Arrival rate must be less than service rate.\n");
        return 1;
    }
    // Compute metrics
    rho = lambda / mu;               // Utilization factor
    P0 = 1.0 - rho;                  // Probability of no waiting
    L = lambda / (mu - lambda);       // Expected number of customers in the bank
    W = 1.0 / (mu - lambda);          // Expected time a customer spends in the bank
    // Print results
    printf("\n=== Bank Queue System Analysis ===\n");
    printf("Probability that a customer will NOT have to wait: %.2lf\n", P0);
    printf("Expected number of customers in the bank: %.2lf\n", L);
    printf("Expected time a customer spends in the bank: %.2lf minutes\n", W);
    return 0;
}

