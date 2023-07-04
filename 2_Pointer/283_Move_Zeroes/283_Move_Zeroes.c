
void moveZeroes(int* nums, int numsSize){
    for(int i=0, j=0; i<numsSize; i++){
        if(nums[i]==0){
            j++;
        } else {
            int temp = nums[i];
            nums[i] = nums[i-j];
            nums[i-j] = temp;
            
        }
    }
}