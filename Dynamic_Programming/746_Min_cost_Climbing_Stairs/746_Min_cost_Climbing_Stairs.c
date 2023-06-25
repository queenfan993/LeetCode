#define MIN(a, b) ((a) < (b)? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize){
    if(costSize == 0) return 0;
    if(costSize == 1) return cost[0];
    if(costSize == 2) return MIN(cost[0], cost[1]);

    // jump to costSize+1 stairs
    int* dp = calloc(costSize+1, sizeof(int));
    dp[0] = 0;
    dp[1] = 0; 

    for( int i = 2; i<costSize+1; i++){
        int min = MIN(cost[i-2]+dp[i-2], cost[i-1]+dp[i-1]);
        dp[i] = min;
    }
    /*
    for( int i = 0; i<costSize+1; i++){
        printf("i: %d\n", dp[i]);
    }
    */
    return dp[costSize];
}
