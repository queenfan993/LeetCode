#define MIN(a, b) ((a) < (b)? (a): (b))
int dfs (int m, int n, int i, int j, int**dp, int** grid) {
    if(i == m-1 && j == n-1) {
        dp[i][j] = grid[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(i != m-1 && j != n-1){ 
        dp[i][j] = grid[i][j] + MIN(dfs(m, n, i+1, j, dp, grid), dfs(m, n, i, j+1, dp, grid));
    } else if( j == n-1){ //from bottom
        dp[i][j] = grid[i][j] + dfs(m, n, i+1, j, dp, grid);
    } else { //from right
        dp[i][j] = grid[i][j] + dfs(m, n, i, j+1, dp, grid);
    }

    return dp[i][j];
}




int minPathSum(int** grid, int m, int* n){
    int** dp = calloc(m, sizeof(int*));
    for(int i = 0; i< m; i++) {
        dp[i] = calloc(*n, sizeof(int));
    }
    for( int i = 0; i < m; i++) {
        for( int j =0; j < *n; j++) {
            dp[i][j] = -1;
        }
    }
    return dfs(m, *n, 0, 0, dp, grid);
}
