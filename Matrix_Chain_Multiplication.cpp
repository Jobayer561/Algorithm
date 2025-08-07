
#include<bits/stdc++.h>
using namespace std;
int mcm(const vector<int>& p, int n, vector<vector<int>>& dp) {
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0; 
    }
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1];
}
int main() {
    int numMatrices;
    cout << "Enter the number of matrices: ";
    cin >> numMatrices;
    vector<int> dimensions(numMatrices + 1);
    cout << "Enter the dimensions (p0 p1 p2 ... p" << numMatrices << "):\n";
    for (int i = 0; i <= numMatrices; i++) {
        cin >> dimensions[i];
    }
    vector<vector<int>> dp(numMatrices + 1, vector<int>(numMatrices + 1, 0));
    int minCost = mcm(dimensions, numMatrices + 1, dp);
    cout << "\nMinimum number of multiplications is: " << minCost << endl;
    int matrixIndex;
    cout << "Enter matrix index (1 to " << numMatrices << ") to check its individual cost: ";
    cin >> matrixIndex;

    if (matrixIndex >= 1 && matrixIndex <= numMatrices) {
        cout << "Cost of multiplying matrix A" << matrixIndex << " is: " << dp[matrixIndex][matrixIndex] << endl;
    } else {
        cout << "Invalid matrix index.\n";
    }
    return 0;
}
