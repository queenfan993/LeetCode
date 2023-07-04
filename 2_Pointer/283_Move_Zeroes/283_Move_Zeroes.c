
void moveZeroes(int* nums, int numsSize){
    for(int i = 0, count = 0; i < numsSize; i++){
        if(nums[i] == 0){
            count++;
        } else {
            int temp = nums[i];
            nums[i] = nums[i-count];
            nums[i-count] = temp;  
        }
    }
}