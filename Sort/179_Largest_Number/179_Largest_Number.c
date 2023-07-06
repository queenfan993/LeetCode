int checkDigit(int temp){
    int digit = 0;
    while(temp) {
        temp /= 10;
        digit++;
    }
    return digit;
}

char* intToString(int temp){
    if(temp==0) return "0";
    int digit = checkDigit(temp);
    char* x = (char*)malloc(sizeof(char)*(digit+1));
    for(int i =0; i< digit; i++){
        x[digit-1-i] = temp % 10 + '0';
        temp /= 10;
    }
    x[digit] = '\0';
    return x;
}

int cmpChar(const void* a, const void* b){
    char* A = *(char**) a;
    char* B = *(char**) b;
    char* AB = (char*)malloc(sizeof(char)*(strlen(A) + strlen(B)+1));ㄌ ㄏ
    char* BA = (char*)malloc(sizeof(char)*(strlen(A) + strlen(B)+1));
    strcpy(AB, A);
    strcpy(AB+strlen(A), B);
    strcpy(BA, B);
    strcpy(BA+strlen(B), A);
    for(int i = 0; i< (strlen(A) + strlen(B)); i++){
        if( AB[i] == BA[i]) 
            continue;
        return BA[i]-AB[i];
    }
    return 0;
}

char * largestNumber(int* nums, int numsSize){
    char** temp = (char**)malloc(sizeof(char*)*numsSize);
    int length = 0;
    bool zero = true ;

    for(int i = 0; i< numsSize; i++){
        temp[i] = intToString(nums[i]);
        length += strlen(temp[i]);
        if(nums[i]) zero = false ;
    }
    if(zero)
        return "0" ;

    qsort(temp, numsSize, sizeof(char*), cmpChar);
    char* ans = (char*)malloc(sizeof(char)*(length+1));
    length = 0;
    
    for(int i = 0; i< numsSize; i++){
        strcpy(ans+length, temp[i]);
        length += strlen(temp[i]);
    }
    ans[length] = '\0';
    return ans;
}








