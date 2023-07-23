/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void letterCombinationsHelper(char * digits, int* returnSize, int level, int* hash, char* out, char** res, char** str) {
    if(level == strlen(digits)) {
        strcpy(res[(*returnSize)++], out);
        return; 
    }

    int number = digits[level] - '2';
    for(int j = 0; j < strlen(str[number]); j++) {
        if(hash[str[number][j] - 'a'] == 0) continue;
        hash[str[number][j] - 'a']-- ;
        out[level] = str[number][j];
        out[level + 1] = '\0';
        letterCombinationsHelper(digits, returnSize, level + 1, hash, out, res, str);
        hash[str[number][j] - 'a']++;
    }
}


char ** letterCombinations(char * digits, int* returnSize){
    if(strlen(digits) == 0) {
        *returnSize = 0;
        char** res = {"0"};
        return res; 
    }
    char *str[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int hash[26] = {0};
    for(int i = 0; i < strlen(digits); i++) {
        int number = digits[i] - '2';
        for(int j = 0; j < strlen(str[number]); j++) {
            hash[str[number][j] - 'a']++;
        }
    }

    int size = 4*4*3*3;

    char** res = calloc(size, sizeof(char*));
    for(int i = 0; i < size; i++) {
        res[i] = calloc(strlen(digits) + 1, sizeof(char));
    }
    
    char* out = calloc(strlen(digits) + 1, sizeof(char));
    *returnSize = 0;
    letterCombinationsHelper(digits, returnSize, 0, hash, out, res, str);
    //free(str);
    free(out);
    return res;
}