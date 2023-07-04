#define RESULT 10000

int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int** res = calloc(RESULT, sizeof(int*));    
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);

    for( int i = 0; i < numsSize-3; ++i ) {
        if((i > 0) && nums[i] == nums[i-1]) continue;
        for( int j = i+1; j < numsSize-2; ++j) {
            if(j > (i + 1) && nums[j] == nums[j-1]) continue;    
            int k = j + 1;
            int l = numsSize-1;
            while(k < l) {
                long long temp = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if(temp > target) {
                    l--;
                } else if(temp < target) {
                    k++;
                } else {
                    //printf("%d,%d,%d,%d\n", i, j, k, l);
                    res[(*returnSize)] = malloc(4 * sizeof(int));
                    res[(*returnSize)][0] = nums[i];
                    res[(*returnSize)][1] = nums[j]; 
                    res[(*returnSize)][2] = nums[k];
                    res[(*returnSize)++][3] = nums[l];
                    k++;
                    l--;
                    while((k < l) && nums[k] == nums[k-1]){
                        k++;
                    }
                    while((l > k) && nums[l] == nums[l+1]){
                        l--;
                    }
                }
            }
        }
    }
    res = realloc(res, (*returnSize) * sizeof(int*));
    returnColumnSizes[0] = malloc((*returnSize) * sizeof(int));
    for(int i = 0; i < (*returnSize); i++){
        returnColumnSizes[0][i] = 4;
    }
    return res;

}