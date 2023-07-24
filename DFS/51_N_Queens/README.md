＃難度： Hard

＃題目說明： 
- 在 n * n 的棋盤上，放 n 個皇后，使皇后們彼此不攻擊對方
- 回傳所有棋盤的組合 char***

＃例子
- Input: n = 4
- Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

＃ Constraints
1 <= n <= 9

＃想法
- 用一個 int* board 去紀錄每一列的 queen 填在哪個 col 上面，index i 表示由上而下的 row
- 遞迴的部分需要注意，怎麼去判斷，下一行 row 可以怎麼填，
- 如果要判斷某一行 row 可不可以把皇后擺在某個 col，需要知道兩點
1. 前面的 row 都沒有把皇后擺在 col 上面過
2. 如果在對角線上有，那斜率會是 1， board[i] - col = 左右距離, i - row = 上下距離 
- 所以合併就會變成下面這樣  
```
for(int i = 0; i < row; i++) {
    if(board[i] == col || abs(board[i] - col) == abs(i - row)){
        return false;
    } 
}
```
- 再來就是遞迴~

＃ 時間複雜度
- 第一行有 n 第二行有 n -1 ....
- O(n!)





    


 


