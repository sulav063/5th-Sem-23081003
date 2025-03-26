#include <stdio.h>
#define MAX 100  // Maximum number of random values
#define INTERVALS 10  // Number of frequency bins
int main() {
    int n, i, observed[INTERVALS] = {0};
    float expected, chi_square = 0.0, random_numbers[MAX];
    // Input: Number of random values
    printf("Enter number of random values (max %d): ", MAX);
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid input!\n");
        return 1;
    }
    // Input: Random numbers (0 to 1)
    printf("Enter %d random numbers (0 to 1):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &random_numbers[i]);
        observed[(int)(random_numbers[i] * INTERVALS)]++; // Categorizing into bins
    }
    // Expected frequency for uniform distribution
    expected = (float)n / INTERVALS;
    // Compute Chi-Square statistic
    for (i = 0; i < INTERVALS; i++) {
        chi_square += ((observed[i] - expected) * (observed[i] - expected)) / expected;
    }
    // Output results
    printf("\nChi-Square Statistic= %.4f\n", chi_square);
    printf(chi_square > 16.92 ? "Sequence is NOT random!\n" : "Sequence appears random!\n");
    return 0;
}

