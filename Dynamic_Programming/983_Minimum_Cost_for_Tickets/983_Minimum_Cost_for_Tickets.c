int mincostTickets(int* days, int daysSize, int* costs, int costsSize){
    int* dp = calloc(days[daysSize-1]+1, sizeof(int));
    dp[0] = 0;
    int j = 0;
    for(int i = 1; i < days[daysSize-1]+1; i++) {
        if(i != days[j]) {
            dp[i] = dp[i-1];
        } else {
            int a = dp[(int)fmax(i-1, 0)] + costs[0];
            int b = dp[(int)fmax(i-7, 0)] + costs[1];
            int c = dp[(int)fmax(i-30, 0)] + costs[2];
            
            dp[i] = fmin(a, fmin(b, c));
            ++j;
        }
    }

    int res = dp[days[daysSize-1]];
    free(dp);
    return res;
}