#include <stdio.h>
#include <stdlib.h>
double calculateMean(double *data, int n) {
    double sum = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}
int main() {
    int n;
    double populationMean;
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
    printf("Enter the population mean: ");
    scanf("%lf", &populationMean);
    double sampleMean = calculateMean(data, n);
    double bias = sampleMean - populationMean;
    printf("\nResults:\n");
    printf("Sample Mean (Point Estimate): %.2lf\n", sampleMean);
    printf("Bias: %.2lf\n", bias);
    free(data);
    return 0;
}

