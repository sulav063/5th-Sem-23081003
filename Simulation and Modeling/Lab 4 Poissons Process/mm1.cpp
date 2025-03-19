#include <iostream>
#include <cmath>
using namespace std;
void mm1_queue(double lambda, double mu, int n) {
    // Check system stability (lambda must be less than mu)
    if (lambda >= mu) {
        cout << "Error: Arrival rate (lambda) must be less than service rate (mu) for a stable system.\n";
        return;
    }
    double rho = lambda / mu;                  // Server utilization (Traffic Intensity)
    double Lq = pow(rho, 2) / (1 - rho);       // Average number of customers in the queue
    double Wq = Lq / lambda;                   // Average time a customer spends in the queue
    double L = lambda / (mu - lambda);         // Average number of customers in the system
    double W = 1 / (mu - lambda);              // Average time a customer spends in the system
    double P0 = 1 - rho;                       // Probability of zero customers in the system
    double Pn = P0 * pow(rho, n);              // Probability of exactly 'n' customers in the system
    // Display results
    cout << "\n=== M/M/1 Queue Metrics ===\n";
    cout << "Traffic Intensity (?) = " << rho << endl;
    cout << "Expected number of customers in queue (Lq) = " << Lq << endl;
    cout << "Expected time in queue (Wq) = " << Wq << " minutes\n";
    cout << "Expected number of customers in system (L) = " << L << endl;
    cout << "Expected time in system (W) = " << W << " minutes\n";
    cout << "Probability of zero customers in system (P0) = " << P0 << endl;
    cout << "Probability of exactly " << n << " customers in system (Pn) = " << Pn << endl;
    cout << "Server Utilization = " << rho << " (should be < 1 for stability)\n";
}
int main() {
    double lambda, mu;
    int n;
    // Get user inputs
    cout << "Enter the Arrival Rate (customers per minute): ";
    cin >> lambda;
    cout << "Enter the Service Rate (customers per minute): ";
    cin >> mu;
    cout << "Enter the number of jobs in the system (n): ";
    cin >> n;
    // Call function to calculate M/M/1 queue metrics
    mm1_queue(lambda, mu, n);
    return 0;
}

