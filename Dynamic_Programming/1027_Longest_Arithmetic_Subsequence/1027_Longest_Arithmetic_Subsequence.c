#define range  501 //for the range given in problem
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int longestArithSeqLength(int* nums, int numsSize){
    int** dp = calloc(numsSize, sizeof(int*));
    for( int i = 0; i < numsSize; i++) {
        dp[i] = calloc(2*range, sizeof(int));
    }
    int max = 2;
    int base = 500;
    for(int i = 0; i < numsSize; i++) {
        for( int j = 0; j < i; j++) {
            int diff = nums[i] - nums[j];
            dp[i][diff + base] = 2;
            if( dp[j][diff + base] != 0 ) {
                dp[i][diff + base] = dp[j][diff + base] + 1;
                max = MAX(max, dp[i][diff + base]);
            }
        }
    }


    return max;
}