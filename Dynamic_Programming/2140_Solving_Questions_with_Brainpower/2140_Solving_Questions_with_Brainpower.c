
long long mostPoints(int** questions, int questionsSize, int* questionsColSize){

    int n = questionsSize;
    long long* dp = malloc( (n+1) * sizeof(long long));
    dp[n] = 0;
    for(int i = n - 1; i >= 0;i--){
        int k = fmin( i + questions[i][1] + 1, n ) ;
        dp[i] = fmax(questions[i][0]+dp[k], dp[i+1]);
    }
  
    /*
    for( int i = 0; i < questionsSize; i++ ) {
        printf("dp[%d]: %d\n", i, dp[i]);
    }
    */
    long long ans = dp[0] ;
    free(dp);  
    return ans;

}