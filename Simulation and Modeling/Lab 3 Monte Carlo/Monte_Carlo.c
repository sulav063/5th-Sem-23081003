#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int i, total_points, points_inside_circle = 0;
    double x, y, pi_estimate;
    printf("Enter the total number of points: ");
    if (scanf("%d", &total_points) != 1 || total_points <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    // Seed the random number generator
    srand(time(NULL));
    for (i = 0; i < total_points; i++) {
        // Generate random points in the range [0, 1]
        x = (double)rand() / (double)RAND_MAX;
        y = (double)rand() / (double)RAND_MAX;
        // Check if the point is inside the unit circle
        if ((x * x + y * y) <= 1.0) {
            points_inside_circle++;
        }
    }
    // Ensure floating-point division
    pi_estimate = 4.0 * ((double)points_inside_circle / (double)total_points);
    printf("Estimated value of PI: %.6f\n", pi_estimate);
    return 0;
}

