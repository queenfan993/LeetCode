#define MAX(a, b) ((a) > (b)? (a) : (b))

int maxProfit(int* prices, int pricesSize){
    int buy = INT_MIN;
    int sell = 0;
    int cool = 0;
    for( int i = 0; i< pricesSize; i++) {
        int preSell = sell;
        sell = buy + prices[i];
        buy = MAX(cool - prices[i], buy); 
        cool = MAX(cool, preSell);
    }
    return MAX(sell, cool);
}