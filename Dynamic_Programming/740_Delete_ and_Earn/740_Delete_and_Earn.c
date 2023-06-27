#define MAX(a, b) ((a)>(b)? (a): (b))

int cmp (const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int process (int* nums, int numsSize, int* dp, int* count) {
    if(numsSize == 0) return -1; 
    if(numsSize == 1) return nums[0];

    dp[0] = nums[0]*count[0];
    if(nums[0]+1 != nums[count[0]]){
        dp[1] = dp[0] + nums[count[0]]*count[1];
    } else {
        dp[1] = MAX(dp[0], nums[count[0]]*count[1]);
    }

    int index = 1;
    for(int i = count[0] + count[1] ; i < numsSize; i += count[index]){
        if(nums[i] != nums[i-1]){
            int temp = ++index; 
            if(nums[i-1] == nums[i]-1){ 
                dp[temp] = MAX(dp[temp-1], dp[temp-2] + (nums[i]* count[temp]));
            } else {
                dp[temp] = MAX(dp[temp-1], dp[temp-2]) + (nums[i]* count[temp]);
            }
        }
    }
    return dp[index];
}



int deleteAndEarn(int* nums, int numsSize){

    qsort(nums, numsSize, sizeof(int), cmp);
    int* dp = malloc(sizeof(int)*numsSize);
    int* count = calloc(numsSize, sizeof(int));
    int index = 0;
    int temp = nums[0];
    for ( int i = 0; i < numsSize; i++) {
        if(temp == nums[i]){
            count[index]++;
        } else{
            count[++index]++;
            temp = nums[i];
        }
    }
    if(index == 0) return nums[0]*count[0]; //all the same 

    return process(nums, numsSize, dp, count);
}
