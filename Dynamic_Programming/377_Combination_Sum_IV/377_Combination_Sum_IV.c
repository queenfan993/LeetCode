int combinationSum4(int* nums, int numsSize, int target){
    long long* dp = calloc(target+1, sizeof(long long));
    dp[0] = 1;
    
    for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < numsSize; j++) {
            if (i >= nums[j]) {
                dp[i] += dp[i - nums[j]];
                if(dp[i] >= INT_MAX){
                    dp[i] = INT_MAX;  
                }
            }
        }
    }
    int result = dp[target];
    free(dp);
    return result;
}