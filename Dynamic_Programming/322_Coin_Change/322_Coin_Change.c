#define MIN(a, b) (a) < (b)? (a): (b)

int coinChange(int* coins, int coinsSize, int amount){
    int array[amount+1];
    array[0]=0;
    for(int i = 1; i < amount+1; i++) {
        array[i] = amount+1;
    }
    for( int i = 1; i < amount+1; i++ ) {
        for( int j = 0; j < coinsSize; j++ ) {
            if( coins[j] <= i )
            {
                array[i] = MIN(array[i],1+array[i-coins[j]]);
            }
        }
    }
    
    if( array[amount] == amount+1 )
        return -1;
    else
        return array[amount];

}