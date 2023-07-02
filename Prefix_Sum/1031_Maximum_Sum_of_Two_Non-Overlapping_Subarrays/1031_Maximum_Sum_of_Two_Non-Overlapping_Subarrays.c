int maxSumTwoNoOverlap(int* nums, int numsSize, int firstLen, int secondLen){
    int* prefix = malloc(sizeof(int)*(numsSize+1));
    prefix[0] = 0;
    int sum;
    int max = 0;
    for(int i=1; i<=numsSize; i++) {
        prefix[i] = prefix[i-1] + nums[i-1];
    }

    for(int i = firstLen; i <= numsSize-secondLen; i++) {
        for(int j = i+secondLen; j <= numsSize; j++) {
            sum = prefix[i] - prefix[i - firstLen];
            sum += prefix[j] - prefix[j - secondLen]; 
            max = fmax(sum, max);
        }
    }

    if(firstLen!=secondLen) {
        for(int i=secondLen; i <= numsSize-firstLen; i++) {
            for(int j = i + firstLen; j <= numsSize; j++) {
                sum = prefix[i] - prefix[i - secondLen];
                sum += prefix[j] - prefix[j - firstLen];
                max = fmax(sum, max);
            }
        }
    }
    return max;
}