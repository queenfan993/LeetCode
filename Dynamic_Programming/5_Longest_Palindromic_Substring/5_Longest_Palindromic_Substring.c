char * longestPalindrome(char * s){
    if(strlen(s) == 1) return s;

    int** dp = malloc(strlen(s) * sizeof(int*));
    for(int i = 0; i< strlen(s); i++) {
        dp[i] = calloc(strlen(s), sizeof(int));

    }
    dp[0][0] = 1;
    dp[1][1] = 1;

    int start = 0, end = 0;
    int max = 0;

    if(s[0] == s[1]) {
        dp[0][1] = 2;
        end = 1;
    }else 
        dp[0][1] = 0;

    for( int i = 2; i<strlen(s); i++) {
        dp[i][i] = 1;
        for( int j = 0; j < i; j++) {
            if(s[i] == s[j] && (j+1) == i){
                dp[j][i] = 2;
            } else if(s[i] == s[j] && dp[j+1][i-1] != 0){
                dp[j][i] = dp[j+1][i-1] + 2;
            } 

            if(max < dp[j][i]){
                max = dp[j][i];
                start = j;
                end = i;
            }
        }
    }
    
    char* temp = malloc(sizeof(char) * (end-start+2));
    for(int i = start; i <= end; i++) {
        temp[i-start] = s[i];
    }

    temp[end - start + 1] = '\0';
    return temp;
}