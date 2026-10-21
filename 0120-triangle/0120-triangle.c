int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int dp[triangleSize];
    for (int i = 0; i < triangleColSize[triangleSize - 1]; i++)
        dp[i] = triangle[triangleSize - 1][i];
    for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j < triangleColSize[i]; j++) {
            if (dp[j] < dp[j + 1])
                dp[j] = triangle[i][j] + dp[j];
            else
                dp[j] = triangle[i][j] + dp[j + 1];
        }
    }
    return dp[0];
}