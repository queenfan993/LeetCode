#define MAX(a,b) (a) > (b)? (a):(b)
int cmp ( const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}


int findCost(int* temp, int size){
    int ans = 0;
    qsort(temp, size, sizeof(int) ,cmp);
    for(int i = 0; i < size-1; i++){
        ans += temp[i];
    }
    return ans;
}


int minCost(char * colors, int* neededTime, int neededTimeSize){
    int ans = 0;
    for(int i = 0; i< strlen(colors); i++) {
        int count = 0;
        while(colors[i] == colors[i+1] && i <= strlen(colors)-2){
            count++;
            i++;
        }
        ans += findCost(&neededTime[i-count], count+1);
    }
    return ans;
}