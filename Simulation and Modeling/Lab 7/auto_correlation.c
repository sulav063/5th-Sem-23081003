#include <stdio.h>
#define MAX 50  // Maximum data points
int main() {
    int n, d, i;
    float data[MAX], sum = 0.0, R_d;
    printf("Enter number of data points (max %d): ", MAX);
    scanf("%d", &n);
    printf("Enter %d random numbers (0 to 1):\n", n);
    for (i = 0; i < n; i++) 
        scanf("%f", &data[i]);
    printf("Enter lag value (d): ");
    scanf("%d", &d);
    if (d >= n) {
        printf("Invalid lag value!\n");
        return 1;
    }
    for (i = 0; i < n - d; i++) 
        sum += data[i] * data[i + d];
    R_d = sum / (n - d);
    printf("Auto-Correlation Coefficient (R_%d) = %.4f\n", d, R_d);
    return 0;
}

