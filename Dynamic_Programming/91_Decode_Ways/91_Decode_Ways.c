int numDecodings(char * s){
    if(s[0] == '0') return 0;
    int* dp = calloc(strlen(s), sizeof(int));
    
    dp[0] = 1;
    //注意 dp 的 i 對應 s 的 i-1，
    for(int i = 1; i < strlen(s); i++) {
        dp[i] = (s[i] == '0')? 0: dp[i-1]; // dp[i-1] 的 都可以直接 append s[i]
        if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
            dp[i] += (i > 1) ? dp[i - 2] : 1;
        }
    }
    
    int res = dp[strlen(s)-1];
    free(dp);
    return res;
}