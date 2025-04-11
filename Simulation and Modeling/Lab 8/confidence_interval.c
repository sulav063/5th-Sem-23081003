#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double calculateMean(double *data, int n) {
    double sum = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}
double calculateStdDev(double *data, int n, double mean) {
    double sum = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        sum += pow(data[i] - mean, 2);
    }    return sqrt(sum / (n - 1));
}

int main() {
    int n;
    double z_score = 1.96;
    printf("Enter the number of data points (sample size): ");
    scanf("%d", &n);
    double *data = (double *)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d data values:\n", n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }
    double sampleMean = calculateMean(data, n);
    double sampleStdDev = calculateStdDev(data, n, sampleMean);
    double marginOfError = z_score * (sampleStdDev / sqrt(n));
    double lowerBound = sampleMean - marginOfError;
    double upperBound = sampleMean + marginOfError;
    printf("\nResults:\n");
    printf("Sample Mean: %.2lf\n", sampleMean);
    printf("Sample Standard Deviation: %.2lf\n", sampleStdDev);
    printf("95%% Confidence Interval: [%.2lf, %.2lf]\n", lowerBound, upperBound);
    free(data);
    return 0;
}

