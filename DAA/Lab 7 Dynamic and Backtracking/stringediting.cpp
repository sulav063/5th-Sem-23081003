#include <iostream>
#include <cstring>

using namespace std;

#define MAX 50

int editDistance(const char *s1, const char *s2)
{
    int dp[MAX][MAX], len1 = strlen(s1), len2 = strlen(s2);

    for (int i = 0; i <= len1; i++){
        for (int j = 0; j <= len2; j++){
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[len1][len2];
}

int main()
{
    char s1[MAX], s2[MAX];

    // Read the first word of the first string
    cout << "Enter the first string: ";
    cin >> s1;

    // Read the first word of the second string
    cout << "Enter the second string: ";
    cin >> s2;

    // Print the edit distance
    cout << "Edit distance: " << editDistance(s1, s2) << endl;

    return 0;
}
