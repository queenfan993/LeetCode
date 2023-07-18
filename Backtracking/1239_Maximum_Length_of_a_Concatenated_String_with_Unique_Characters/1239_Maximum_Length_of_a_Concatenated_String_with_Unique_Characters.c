int onesFind(int mask){
    //for recording alphebat 26
    int ones = 0;
    for(int i = 0; i< 26; i++){
        if(mask << i)
            ones++;
    }
    return ones;
}



void dfs(int* a, int arrSize, int* max, int mask, int pos) {
    *max = fmax(*max, onesFind(mask));
    for (int i = pos; i<arrSize; i++) {
        if((mask & a[i]) == 0) {
            dfs(a, arrSize, max, mask|a[i], i+1);
        }
    }
}



int maxLength(char ** arr, int arrSize){
    int* a = calloc(arrSize, sizeof(int));
    for( int i = 0; i< arrSize; ++i){
        int mask = 0;
        bool unique = true;
        for( int j = 0; j = strlen(arr[i]); ++j) {
            if( mask & (1 << (arr[i][j] - 'a'))) {
                unique = false;
                break;
            }
            if(unique){
                a[i] |= mask;
            } else {
                a[i] = 0;
            }
        }
    }
    int max = 0;
    dfs(a, arrSize, &max, 0, 0);
    return max;
}