#define MAX(a,b) ((a) > (b)? (a):(b))
int longestSubsequence(int* arr, int arrSize, int difference){
    int dp[20001] = {0}; 

    int base = 10000;
    int max = 1;
    
    for( int i = 0; i < arrSize; i++) {
        if(difference!=0){
            if(dp[arr[i] + base] == 0) {
                dp[arr[i] + base] ++;
            }
        }
        

        if((arr[i] + base - difference) <= 20000 && (arr[i] + base - difference) >=0 ){
            //printf("%d\n",(arr[i] + base - difference));
            dp[arr[i] + base] = dp[arr[i] + base - difference] + 1; 
            max = MAX(max, dp[arr[i] + base]);
        }
    }



    return max;
}