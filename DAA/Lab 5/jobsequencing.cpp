#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void JobSequencing(Job jobs[], int n) {
    sort(jobs, jobs + n, compare);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }
    
    int slots[maxDeadline + 1];
    fill(slots, slots + maxDeadline + 1, -1);
    int totalProfit = 0;
    cout << "Selected Jobs: ";
    
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                cout << jobs[i].id << " ";
                break;
            }
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    Job jobs[n];
    cout << "Enter job details (ID Deadline Profit):\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    JobSequencing(jobs, n);
    return 0;
}

