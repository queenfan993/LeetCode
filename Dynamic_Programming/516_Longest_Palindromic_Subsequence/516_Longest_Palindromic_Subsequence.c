#define MAX(a,b) ((a)>(b)? (a):(b))
int dynamic(char *str, int** dp) {
    int n = strlen(str);
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i < n-len+1; i++) {
            int j = i+len-1;
            if(str[i] == str[j] && len == 2) {
                dp[i][j] = 2;
            } else if(str[i] == str[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = MAX(dp[i][j-1], dp[i+1][j]);
            }
        }
    }
    return dp[0][n-1];
}

int longestPalindromeSubseq(char * s){
    if(strlen(s) == 1) return 1;
    int max = 1;
    int** dp = calloc(strlen(s), sizeof(int*));
    for(int i = 0; i< strlen(s); i++) {
        dp[i] = malloc(sizeof(int)*strlen(s));
        dp[i] = memset(dp[i], -1, sizeof(dp[i]));
    }
    return dynamic(s, dp);
}