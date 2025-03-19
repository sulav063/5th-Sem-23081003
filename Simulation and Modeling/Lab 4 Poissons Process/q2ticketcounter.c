#include <stdio.h>
int main() {
    // Given data
    double lambda = 1.0;      // Arrival rate (customers per minute)
    double mu = 3.0;          // Service rate (customers per minute)
    double seat_time = 1.5;   // Time to reach the seat after purchase
    // Utilization factor (traffic intensity)
    double rho = lambda / mu;
    // Expected number of customers in the system (L)
    double L = lambda / (mu - lambda);
    // Expected time in the system (waiting + service time)
    double W = 1.0 / (mu - lambda);
    // Total time spent before being seated
    double total_time = W + seat_time;
    // Print results
    printf("=== Football Stadium Ticket Queue Analysis ===\n");
    printf("Probability of immediate service: %.2lf\n", 1 - rho);
    printf("Expected number of people in the system: %.2lf\n", L);
    printf("Time spent in queue + service time: %.2lf minutes\n", W);
    printf("Total time to be seated: %.2lf minutes\n", total_time);
    // Check if the fan will be seated before kickoff
    if (total_time <= 2.0)
        printf("\nThe sports fan will be seated in time for kickoff!\n");
    else
        printf("\nThe sports fan may miss the kickoff.\n");
    return 0;
}

