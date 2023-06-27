int dfs(int m, int n, int i, int j, int**dp){
    if(i == m-1 && j == n-1) {
        dp[i][j] = 1;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    if(i != m-1) {
        dp[i][j] += dfs(m, n, i+1, j, dp); 
    }
    if(j != n-1) {
        dp[i][j] += dfs(m, n, i, j+1, dp); ;
    }
    return dp[i][j];
}



int uniquePaths(int m, int n){
    int** dp = calloc(m, sizeof(int*));
    for(int i = 0; i< m; i++) {
        dp[i] = calloc(n, sizeof(int));
    }

    return dfs(m, n, 0, 0, dp);
}
