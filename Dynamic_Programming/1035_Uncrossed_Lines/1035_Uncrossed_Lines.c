#define MAX(a,b) ((a)>(b)?(a):(b))
int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int** dp = (int**)malloc(nums1Size*sizeof(int*));

    for( int i = 0; i < nums1Size; i++ ){
    	dp[i] = (int*)calloc(nums2Size, sizeof(int));
    }
    for( int i = 0; i < nums1Size; i++ ){
        for( int j = 0; j < nums2Size; j++ ){
            if(nums1[i] == nums2[j]) {
                dp[i][j] = ((i && j)? dp[i-1][j-1]: 0) +1;
            } else {
                dp[i][j] = MAX( i>0 ? dp[i-1][j] : 0, j>0 ? dp[i][j-1] : 0 );
            }
        }
    }
    return dp[nums1Size-1][nums2Size-1];

}