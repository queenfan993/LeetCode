char* preProcess(char* s) {
    const int len = strlen(s);
    const int n = (len) * 2 + 1;
    
    char* pre = calloc((n + 1), sizeof(char));
    pre[0] = '#';
    int index = 1;
    for(int i = 0; i < len; i++) {
        pre[index++] = s[i];
        pre[index++] = '#';
    }

    pre[n] = '\0';
    return pre;
}   

char * longestPalindrome(char * s){
    if(strlen(s) == 1) return s;

    char* pre = preProcess(s);
    const int preLen = (strlen(s) * 2) + 1;

    int* dp = calloc(preLen, sizeof(int));

    int center = 0;
    int right = 0;
    for(int i = 0; i < preLen; i++) {
        const int mirror = 2 * center - i;
        if(i < right) {
            dp[i] = fmin(right - i, dp[mirror]);
        }

        int a = i + (1 + dp[i]); // spread to right
        int b = i - (1 + dp[i]); // to left
        while(a < preLen && b >= 0 && pre[a] == pre[b]) {
            dp[i]++;
            a++;
            b--;
        }

        //if over the right limit
        if(i + dp[i] > right) {
            center = i;
            right = i + dp[i];
        }
    }

    int returnSize = 0;
    int start = 0;
    for(int i = 0; i < preLen; i++) {
        if(dp[i] > returnSize) {
            returnSize = dp[i];
            start = (i - returnSize) / 2;
        }
    }

    char* res = malloc((returnSize +1) * sizeof(char));
    for(int i = 0; i < returnSize; i++) {
        res[i] = s[start + i];
    }
    res[returnSize] = '\0';

    free(pre);
    free(dp);
    return res;
}