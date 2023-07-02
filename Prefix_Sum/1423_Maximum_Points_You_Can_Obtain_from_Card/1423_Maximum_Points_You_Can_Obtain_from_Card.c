#define MAX(a,b) (a)>(b)? (a):(b) 

int maxScore(int* cardPoints, int cardPointsSize, int k){
    int* prefix = (int*)malloc(sizeof(int)*(k+1));
    int* suffix = (int*)malloc(sizeof(int)*(k+1));
    prefix[0] = 0;
    suffix[0] = 0;
    for (int i = 1; i<=k; i++){

        prefix[i] = prefix[i-1] + cardPoints[i-1];
        suffix[i] = suffix[i-1] + cardPoints[cardPointsSize-i];

    }
    int max = INT_MIN;
    for (int i =0; i<=k; i++){
        max = MAX(max, prefix[i]+suffix[k-i]);
    }
    return max;
}