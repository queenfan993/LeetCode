/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct pairs {
    int val;
    int index;
} pairs;

int cmp(const void* a, const void* b) {
    pairs* p = (pairs*) a;
    pairs* q = (pairs*) b;
    return p -> val - q ->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    pairs* pair = calloc(numsSize, sizeof(pairs));
    for(int i = 0; i < numsSize; i++) {
        pair[i].index = i;
        pair[i].val = nums[i]; 
    }

    qsort(pair, numsSize, sizeof(pairs), cmp);
    int r = numsSize-1, l = 0;
    int temp;
    
    while(r >= l) {
        temp = pair[r].val + pair[l].val;
        if(temp == target) {
            break;
        } else if(temp < target) {
            l++;
        } else {
            r--;
        }
    }
    *returnSize = 2;
    int* result = calloc(*returnSize, sizeof(int));

    result[0] = pair[l].index;
    result[1] = pair[r].index;   
    return result;
}