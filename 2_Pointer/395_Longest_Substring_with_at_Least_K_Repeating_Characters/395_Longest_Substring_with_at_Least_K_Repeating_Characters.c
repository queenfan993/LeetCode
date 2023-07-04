#define alphabet    26

int longestSubstring(char* s, int k) {
    int res = 0, n = strlen(s);
    for (int cnt = 1; cnt <= alphabet; ++cnt) {
        int start = 0, uniqueCnt = 0;
        int* hash = calloc(alphabet, sizeof(int));
        for(int end = 0; end < n; end++){
            if (hash[s[end] - 'a']++ == 0) uniqueCnt++;
            
            while (uniqueCnt > cnt)
                if (--hash[s[start++] - 'a'] == 0) uniqueCnt--;
            
            bool valid = true;
            for (int j = 0; j < alphabet; ++j) {
                if (hash[j] > 0 && hash[j] < k) {
                    valid = false; 
                    break;
                }
            }
            if(valid) res = fmax(res, end - start + 1);                
        }
    }    
    return res;
}