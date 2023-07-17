int numTilings(int n){
    if(n < 2) return 1;
    if(n == 2) return 2;
    int M = 1e9 + 7;
    long long * dp = calloc(n+1, sizeof(long long));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = (2 * (dp[i-1] % M) + (dp[i-3] % M)) % M;
    }
    int res = dp[n];
    free(dp);
    return res;
}