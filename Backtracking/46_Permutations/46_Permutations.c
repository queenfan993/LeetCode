/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


void permuteHelpler(int* nums, int numsSize, int** res, int curSize, int* hash, int* out, int* rIdx){  
    if(curSize == numsSize) {
        for(int i = 0; i < numsSize; i++) {
            
            res[(*rIdx)][i] = out[i]; 
        }
        //printf("rindex: %d", *rIdx);
        (*rIdx)++;
        return;
    }
    for(int i = 0; i < numsSize; i++) {
        if(hash[i] == 1) continue;
        hash[i] = 1;
        out[curSize] = nums[i];
        /*
        for(int j = 0; j < curSize+1; j++) {
            printf("%d", out[j]);
        }
        printf("\n");
        */
        permuteHelpler(nums, numsSize, res, curSize + 1, hash, out, rIdx);
        hash[i] = 0;
    }
} 


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 1;
    for(int i = 2; i <= numsSize; i++) {
        (*returnSize) *= i;
    }

    int** res = calloc((*returnSize), sizeof(int*));
    *returnColumnSizes = calloc((*returnSize), sizeof(int));
    for(int i = 0; i < (*returnSize); i++) {
        res[i] = calloc(numsSize, sizeof(int));
        (*returnColumnSizes)[i] = numsSize;
    }
    
    int* hash = calloc(numsSize, sizeof(int));

    int* out = calloc(numsSize, sizeof(int));
    int rIdx = 0;
    permuteHelpler(nums, numsSize, res, 0, hash, out, &rIdx);
    
    
    return res;
}