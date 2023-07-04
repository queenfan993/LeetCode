int cmpfunc (const void * a, const void * b){
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int result = nums[0]+nums[1]+nums[2];
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for(int i =0; i < numsSize-2; i++) {
        int l = i + 1;
        int r = numsSize - 1;
        int sum = nums[i] + nums[l] + nums[r];
        while(l<r){
            int sum = nums[i] + nums[l] + nums[r];
            if(sum > target){
                r--;
            } else{
                l++;
            }

            if(target == sum){
                return sum;
            } else if(abs(target-result) > abs(target -sum)) { 
                result = sum;
            } 
        }  
    }
    return result;
}