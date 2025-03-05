#include <stdio.h>
int main() {
    // Given data
    double G[] = {20, 25, 30, 35, 40}; // Government expenditure for each year
    double Y_prev = 80;               // Initial Y (Y_-1)\
    // Variables
    double I, Y, T, C;
    double growth_in_consumption;
    int year;  // Declare the variable here
    // Loop through 5 years
    printf("Year\tG\tI\tY\tT\tC\tGrowth in Consumption\n");
    for (year = 0; year < 5; year++) {  // Use the declared variable
        // Calculate I
        I = 2 + 0.1 * Y_prev;

        // Calculate Y
        Y = 45.45 + 2.27 * (I + G[year]);

        // Calculate T
        T = 0.2 * Y;

        // Calculate C
        C = 20 + 0.7 * (Y - T);

        // Calculate growth in consumption
        growth_in_consumption = C - (20 + 0.7 * (Y_prev - 0.2 * Y_prev));

        // Print results for the current year
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", year + 1, G[year], I, Y, T, C, growth_in_consumption);

        // Update Y_prev for the next year
        Y_prev = Y;
    }
    return 0;
}

