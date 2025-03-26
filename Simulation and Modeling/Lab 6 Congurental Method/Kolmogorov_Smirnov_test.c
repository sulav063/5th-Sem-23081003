#include <stdio.h>
#include <stdlib.h>
#define MAX 50  // Max data points
// Function to sort the array (Bubble Sort for compatibility)
void sort(float arr[], int n) {
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Kolmogorov-Smirnov Test Function
void kolmogorov_smirnov(float data[], int n) {
    float D_plus[MAX], D_minus[MAX], D, max_D_plus = 0, max_D_minus = 0;
    int i;
    // Sorting the data
    sort(data, n);
    printf("\nSorted Data:\n");
    for (i = 0; i < n; i++) {
        printf("%.4f ", data[i]);
    }
    printf("\n\n");
    // Computing D+ and D-
    for (i = 0; i < n; i++) {
        float F_empirical = (float)(i + 1) / n;  // Empirical CDF
        float F_theoretical = data[i];  // Theoretical CDF (Uniform Distribution assumption)
        D_plus[i] = F_empirical - F_theoretical;
        D_minus[i] = F_theoretical - (float)i / n;
        if (D_plus[i] > max_D_plus) max_D_plus = D_plus[i];
        if (D_minus[i] > max_D_minus) max_D_minus = D_minus[i];
        printf("i: %d | X: %.4f | F_emp: %.4f | F_theo: %.4f | D+: %.4f | D-: %.4f\n", 
               i + 1, data[i], F_empirical, F_theoretical, D_plus[i], D_minus[i]);
    }
    // Maximum D-value
    D = (max_D_plus > max_D_minus) ? max_D_plus : max_D_minus;
    printf("\nMax D+ = %.4f, Max D- = %.4f\n", max_D_plus, max_D_minus);
    printf("Kolmogorov-Smirnov D-value = %.4f\n", D);
}

int main() {
    int n, i;
    float data[MAX];
    printf("Enter the number of data points (max %d): ", MAX);
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid input. Exiting program.\n");
        return 1;
    }
    printf("Enter %d data values (between 0 and 1):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &data[i]);
    }
    kolmogorov_smirnov(data, n);
    return 0;
}

