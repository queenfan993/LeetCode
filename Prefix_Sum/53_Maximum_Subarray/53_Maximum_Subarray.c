#define MAX(a,b) ((a) > (b))? (a):(b)

int maxSubArray(int* nums, int numsSize){
    int temp = nums[0], result = nums[0];
    for(int i =1; i<numsSize; i++){
        if(temp>=0){
            temp+=nums[i];
        }
        else{
            temp = nums[i];
        }
        result = MAX(result, temp);
    }
    return result;
}