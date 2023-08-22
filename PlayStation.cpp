bool isMatch(string A, string B) {
    int m = A.size();
    int n = B.size();

    // Initialize DP table
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    // Initialize first row for matching empty string
    for (int j = 1; j <= n; ++j) {
        if (B[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (B[j - 1] == '?' || A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (B[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}
