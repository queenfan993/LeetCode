/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return *(int*) a - *(int*) b;
}

int* newSet(){
    int* temp = (int*)malloc(sizeof(int)*3);
    return temp;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int size = 1;
    qsort(nums, numsSize, sizeof(int), cmp);
    int** result = (int**)malloc(sizeof(int*)*100000);
    result[0] = newSet();
    for(int i =0; i < numsSize-2; i++){
        if (i == 0 || nums[i] != nums[i-1]) {
            //printf("i: %d\n", i);
            int j = i+1;
            int k = numsSize-1;
            while(j < k){
                if((nums[i]+nums[j]+nums[k]) > 0) {
                    k--;
                } else if((nums[i]+nums[j]+nums[k]) < 0) {
                    j++;
                } else {
                    if(size!=1) {
                        //result = (int**)realloc(result, sizeof(int*)* size);
                        result[size-1] = newSet();
                    }         
                    result[size-1][0] = nums[i];
                    result[size-1][1] = nums[j];
                    result[size-1][2] = nums[k];
                    size++;
                    j++;
                    
                    while (j < k && nums[j] == nums[j-1])
                        j++;
                    
                }           
            }
        }
    }

    *returnSize = size-1;
    *returnColumnSizes = malloc(sizeof(int*)*(size-1));
    for(int i =0; i<size-1; i++){
        (*returnColumnSizes)[i] = 3;
    }
    return result;
}