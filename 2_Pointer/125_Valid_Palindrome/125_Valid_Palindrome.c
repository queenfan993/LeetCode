bool isPalindrome(char * s){
    int l = 0, r = strlen(s)-1;

    while(r >= l) {
        while(r > l && !isalnum(s[r])){
            r--;
        }
        while(r > l && !isalnum(s[l])) {
            l++;
        }
        if(tolower(s[l]) != tolower(s[r])) {
            return false;
        }
        r--;
        l++;   
    }
    return true;
}