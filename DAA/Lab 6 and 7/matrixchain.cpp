#include <iostream>
#include <climits>

using namespace std;

void MatrixChainMultiplication(int p[], int n)
{
    int m[n][n], s[n][n];

    // Initialize the main diagonal to 0
    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    // Compute the cost for chains of increasing length
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;
}

int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int p[n + 1]; // Array to store matrix dimensions

    cout << "Enter the dimensions: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    MatrixChainMultiplication(p, n + 1);
    return 0;
}
