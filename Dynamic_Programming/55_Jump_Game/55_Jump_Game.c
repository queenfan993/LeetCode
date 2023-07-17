bool canJump(int* nums, int numsSize){
    if(numsSize == 1) return true;
    if(nums[0] == 0) return false;
    int max = 0;
    for(int i = 0; i < numsSize-1; i++) {
        if(max >= i){
            max = fmax(nums[i] + i, max);
        }
    }
    if(max >= numsSize-1) return true;
    else return false;
}