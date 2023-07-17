#define MAX(a, b) ((a)>(b)?(a):(b))

int cmp ( const void* a, const void* b) {
    const int *ia = *(const int **)a;
    const int *ib = *(const int **)b;
    return ia[0] - ib[0];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize){
    if(pairsSize==1) return 1;
    qsort(pairs, pairsSize, sizeof(int*) ,cmp);

    int* dp = calloc(pairsSize, sizeof(int));
    for(int i = 0; i < pairsSize; i++){
        dp[i] = 1;
    }


    for( int i = 0; i< pairsSize; i++ ) {
        for( int j = 0; j < i; j++) {
            if(pairs[i][0] > pairs[j][1]) {
                dp[i] = MAX(dp[i], dp[j]+1);
            }
        }
    }

    int max = INT_MIN;
    for(int i = 0; i<pairsSize; i++) {
        max = MAX(dp[i], max);
    }

    return max;
}