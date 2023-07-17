
int dynamic (char * s1, char * s2, int**dp) {
    for(int i = 1; i <= strlen(s1); i++) {
        for(int j = 1; j <= strlen(s2); j++){
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+s1[i-1];  
                //printf("%d\n", dp[i][j]);
            } else {
                dp[i][j] = (dp[i-1][j] < dp[i][j-1])? dp[i][j-1]: dp[i-1][j];
                //printf("%d\n", dp[i][j]);
            }
        }
    } 
    return dp[strlen(s1)][strlen(s2)];
}



int minimumDeleteSum(char * s1, char * s2){
    
    int** dp = calloc(strlen(s1)+1, sizeof(int*));
    for(int i = 0; i< (strlen(s1)+1); i++) {
        dp[i] = calloc((strlen(s2)+1),sizeof(int));
    }
    int temp = 0;
    for(int i = 0; i< strlen(s1); i++){
        temp += s1[i]; 
    }
    for(int i = 0; i< strlen(s2); i++) {
        temp += s2[i];
    }
    //printf("%d\n", dynamic(s1, s2, dp));
    return temp - (2*dynamic(s1, s2, dp));
}