int profitCount(int* prices, int*profit, int size){
    //every time turn positive;
    int earn = 0;
    for(int i = 0; i<size-1; i++){
        if(profit[i]>0){
            earn = earn + prices[i+1]-prices[i];
            //printf("buy day: %d", i);
        }
    }
    return earn;    
}

int maxProfit(int* prices, int pricesSize){
    if(pricesSize==0 || pricesSize==1){
        return 0;
    }
    int profit[pricesSize-1];
    for(int i = 0; i<pricesSize-1; i++){
        profit[i] = prices[i+1]-prices[i];
        //printf("profit: %d\n", profit[i]);
    }

    return profitCount(prices, profit, pricesSize);
}
