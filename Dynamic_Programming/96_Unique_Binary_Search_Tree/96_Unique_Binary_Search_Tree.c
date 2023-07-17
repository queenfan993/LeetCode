
// [1......j......n]
// dp[j] 可以分成左右兩棵樹
// dp[n] = dp[j-1] + dp[n-j]
// 先算 n 
// 再算 i in n 

int numTrees(int n){
    int* dp = calloc(n+1,sizeof(int));

    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < n+1; i++) {
        for(int j = 0; j < i; j++ ){
            //printf("%d, %d\n", i, j);
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}