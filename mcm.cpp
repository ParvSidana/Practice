#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to solve Matrix Chain Multiplication using DP
int matrixChainOrder(const vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    // Example: dimensions of matrices A1(10x30), A2(30x5), A3(5x60)
    vector<int> dims = {10, 30, 5, 60};
    cout << "Minimum number of multiplications: " << matrixChainOrder(dims) << endl;
    return 0;
}
