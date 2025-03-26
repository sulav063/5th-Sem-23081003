#include <stdio.h>
#include <stdlib.h>
#define MAX 50  // Maximum random numbers
// Function to count unique digits in a 5-digit group
int count_unique_digits(int num) {
    int digits[10] = {0}, count = 0, digit;
    while (num > 0) {
        digit = num % 10;
        if (digits[digit] == 0) {
            digits[digit] = 1;
            count++;
        }
        num /= 10;
    }
    return count;
}
int main() {
    int n, i, groups, num, unique_count[6] = {0};  // To store frequency of unique digits
    printf("Enter the number of random numbers (max %d): ", MAX);
    scanf("%d", &n);
    if (n < 5 || n > MAX) {
        printf("Invalid input! Enter at least 5 numbers.\n");
        return 1;
    }
    groups = n / 5;  // Number of 5-digit groups
    printf("Enter %d numbers (each 5-digit long):\n", groups);
    for (i = 0; i < groups; i++) {
        scanf("%d", &num);
        if (num < 10000 || num > 99999) {
            printf("Invalid input! Enter a 5-digit number.\n");
            return 1;
        }
        unique_count[count_unique_digits(num)]++;
    }
    // Calculate Poker Test Statistic
    float X2 = 0.0;
    for (i = 1; i <= 5; i++) 
        X2 += (unique_count[i] * unique_count[i]);

    X2 = ((10.0 / groups) * X2) - groups;
    // Output results
    printf("\nPoker Test Statistic (X^2) = %.4f\n", X2);
    printf(X2 > 9.49 ? "Sequence is NOT random!\n" : "Sequence appears random!\n");
    return 0;
}

