int next_maximum_jump(int* nums, int present, int numsSize);
int jump(int* nums, int numsSize){
    int temp, count = 0;
    if(numsSize == 1) return 0;
    if(nums[0] >= numsSize-1) return 1;
    while(temp < numsSize-1){
        count ++;
        temp = next_maximum_jump(nums, temp, numsSize);
    }
    return count;
}

int next_maximum_jump(int* nums, int present, int numsSize){
    int temp, i, maximum = 0;
    for(i = 1; i < nums[present]+1; i++){
        printf("find i: %d\n", i);
        if(present +i < numsSize-1){
            //printf("find i: %d\n", i);
            if(maximum < i + nums[present +i]){ 
                maximum = i + nums[present +i];
                temp = present + i;
            }
        }
        else return numsSize;
    }
    return temp;
}