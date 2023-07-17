#define MAX(a, b) ((a)>(b)?(a):(b))

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize == 1) return 1;
    int* dp = calloc(numsSize, sizeof(int*));

    for(int i = 0; i <= numsSize; i++){
        dp[i] = 1;
    }

    // nums[i] 可以接在誰後面，用 j 從頭開始掃
    for(int i = 0; i<numsSize; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]){
                dp[i] = MAX(dp[i], dp[j]+1);
            }
        } 
    }
    int max = INT_MIN;
    for(int i = 0; i <= numsSize; i++){
        max = MAX(max, dp[i]);
    }
    
    return max;
}