#define MAX(a,b) ((a) > (b)? (a) : (b))

int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1);
    int len2 = strlen(text2);

    int** dp = calloc(len1, sizeof(int*));
    for(int i = 0; i < len1; i++) {
        dp[i] = calloc(len2, sizeof(int));
    }
    
    for(int i = 0; i < len1; i++) {
        for(int j = 0; j < len2; j++) {
            //printf("%d, %d\n", i, j);
            if(text1[i] == text2[j]){
                dp[i][j] = ((i && j) ? dp[i-1][j-1] : 0 ) + 1;
                //printf("aaa\n");
            } else {
                dp[i][j] = MAX( (i > 0) ? dp[i-1][j] : 0, (j > 0) ? dp[i][j-1] : 0);
                //printf("bbb\n");
            }
        }
    }

    return dp[len1-1][len2-1];
}