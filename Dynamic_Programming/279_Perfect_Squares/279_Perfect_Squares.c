int numSquares(int n){
    int* dp = calloc(n+1 ,sizeof(int));
    
    for(int i = 0; i <= n; i++){
        dp[i] = i;
        for(int j = 1; j*j <= i; j++) { 
            dp[i] = fmin(dp[i],  dp[i-j*j] + 1); 
        }
        //printf("dp[%d]: %d\n", i, dp[i]);
    }

    return dp[n];
}