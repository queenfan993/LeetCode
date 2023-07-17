//coins 1 2 5
// dp 0 1 2 3 4 5
//    0 1 2 2 3 4
// if dp[i-coin[j]] != 0
// dp[i] += dp[i-coin[j]] 

int change(int amount, int* coins, int coinsSize){
    int* dp = calloc(amount+1, sizeof(int));
    dp[0] = 1; // 如果等於 coin 的時候
    for (int j = 0; j < coinsSize; j++ ) {
        for (int i = coins[j]; i <= amount; ++i) {
            dp[i] += dp[i - coins[j]];
            printf("dp[%d]: %d, coin[%d]: %d\n", i, dp[i], j, coins[j]);
        }
    }
    
    

    int result = dp[amount];
    free(dp);

    return result;
}