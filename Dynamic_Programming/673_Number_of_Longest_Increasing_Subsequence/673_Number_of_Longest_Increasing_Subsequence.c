#define MAX(a, b) ((a)>(b)?(a):(b))


//用 dp [i] 表示在 i 位置的子序列長度
//用 cnt[i] 表示以 i 位置為結尾的子序列個數
//當 dp 求出來，如果 dp[i] > dp[j] 

int findNumberOfLIS(int* nums, int numsSize){
    if(numsSize == 1) return 1;
    int* dp = calloc(numsSize, sizeof(int*));
    int* cnt = calloc(numsSize, sizeof(int*)); //以 nums[i] 結尾的序列有多少個

    for(int i = 0; i <= numsSize; i++){
        dp[i] = 1;
        cnt[i] = 1;
    }

    // nums[i] 可以接在誰後面，用 j 從頭開始掃
    for(int i = 0; i<numsSize; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]){
                if(dp[j] + 1 > dp[i]) { // 第一次
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                } else if(dp[j]+1 == dp[i]) { //第二次以後
                    cnt[i] += cnt[j];
                }
            }
        } 
    }


    int max = INT_MIN;
    for(int i = 0; i < numsSize; i++){
        max = MAX(max, dp[i]);
        printf("%d: %d\n", i, dp[i]);
    }
    int numbers = 0;
    for(int i = 0; i < numsSize; i++){
        if(dp[i] == max){
            numbers += cnt[i];
        }
    }

    return numbers;
}
