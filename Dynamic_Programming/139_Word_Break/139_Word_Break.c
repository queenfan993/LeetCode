char* helpler(char* s, int start, int end) {
    //printf("%d, %d\n", start, end);
    char* res = calloc(end - start + 2, sizeof(char));
    for(int i = start; i <= end; i++) {
        res[i-start] = s[i]; 
    }
    res[end -start + 1] = '\0';
    //printf("%s\n", res);
    return res;
}



bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int len = strlen(s);
    bool* dp = calloc(len+1, sizeof(bool));
    
    dp[0] = true;
    //printf("%s\n", helpler(s, 3,3));
    
    for(int i = 0; i < len; i++) {
        if(dp[i]) {
            for(int j = i; j < len; j++) {
                for(int k = 0; k < wordDictSize; k++) {
                    if(strcmp(helpler(s, i, j), wordDict[k]) == 0) {
                        dp[j+1] = true;
                        break;
                    }
                }
            }
        }
        if(dp[len]) return true;
    }
    
    
    for(int i = 0; i < len; i++) {
        printf("%d\n", dp[i]);
    }
    
    bool result = dp[len];
    free(dp); 
    return result;
}


/* for the backtracking
void wordBreakHelpler(char* s, char** wordDict, int wordDictSize, int* curSize, char* res, bool* ans) {
    if(*ans == true) return;
    if(*curSize >= strlen(s)) {
        return;
    }

    for(int i = 0; i < wordDictSize; i++) {
        strcat(res, wordDict[i]);
        if(strcmp(res, s) == 0) {
            *ans = true;
            return; 
        }
        //printf("%s\n", res);
        (*curSize) = strlen(res);
        wordBreakHelpler(s, wordDict, wordDictSize, curSize, res, ans);
        
        // originally i write (*cursize) in the below line, the take off from res bottom may occur error
        // switch as strlen(res)
        memset(res + (strlen(res)) - strlen(wordDict[i]), '\0', strlen(wordDict[i]));
        
        //printf("leave: %s\n", res);
    }
}


bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    if(strlen(s)==0) return false;
    int max = 0;
    for(int i = 0; i < wordDictSize; i++) {
        fmax(max, strlen(wordDict[i]));
    }
    bool ans = false;
    int curSize = 0;
    char* res = calloc(strlen(s)+2*max, sizeof(int));
   
    wordBreakHelpler(s, wordDict, wordDictSize, &curSize, res, &ans);
    free(res);
    return ans;
}
*/