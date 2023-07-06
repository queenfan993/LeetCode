/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    const int* arr1 = *(const int**)a;
    const int* arr2 = *(const int**)b;
    return arr1[0] - arr2[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int* temp;
    int count = 0;
    
    if(intervals == NULL || intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    
    temp = intervals[0];
    for(int i = 1; i < intervalsSize; i++) {
        if(temp[1] >= intervals[i][0]) {
            temp[1] = (temp[1] > intervals[i][1])? temp[1] : intervals[i][1];
        } else {
            memcpy(intervals[count], temp, sizeof(temp));
            count++;
            temp = intervals[i];
        }
    }
    memcpy(intervals[count], temp, sizeof(temp));
    count++;

    *returnSize = count;
    (*returnColumnSizes) = (int*)malloc(count*sizeof(int));
    for(int i = 0; i < count; i++)
    {
        (*returnColumnSizes)[i] = 2;
    }
    return intervals;
}