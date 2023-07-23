/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs (int* nums, int numsSize, int length, int* i, int j, int** res, int* buffer) {
    if( j > numsSize-1 && (*i) < length ) {
        for( int x = 0; x< numsSize; x++) {
            res[*i][x] = buffer[x];
        }
        (*i)++;
        return;
    }
    buffer[j] = nums[j];
    dfs(nums, numsSize, length, i, j+1, res, buffer); // 到下一層去 
    buffer[j] = -11;
    dfs(nums, numsSize, length, i, j+1, res, buffer); 
}


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = pow(2, numsSize);
    int** result = calloc(*returnSize, sizeof(int*));
    for( int i = 0; i< *returnSize ; i++ ) {
        result[i] = calloc(numsSize, sizeof(int));
    }
    // construct buffer
    int* buffer = calloc(numsSize, sizeof(int));
    for(int i = 0; i< numsSize; i++){
        buffer[i] = -11;
    }

    int i = 0;
    dfs(nums, numsSize, *returnSize, &i, 0, result, buffer); 
    *returnColumnSizes = calloc(*returnSize, sizeof(int));

    for(int i = 0; i < *returnSize; i++ ) {
        int count = 0;
        for(int j = 0; j<numsSize; j++){
            if(result[i][j] != -11){
                count++;
                int k = j;
                if(k!=0){
                    while(result[i][k-1] == -11 ){
                        result[i][k-1] = result[i][k];
                        result[i][k] = -11;
                        k--;
                        if(k == 0 ) break;
                    }
                }
            }
        }
        (*returnColumnSizes)[i] = count;
    }
    /*
    for( int i = 0; i< *returnSize ; i++ ) {
        printf("result");
        for (int j = 0; j< numsSize; j++){
            printf("%d", result[i][j]);
        }
        printf("\n");
    } 
    */
    return result;
}