＃難度： Medium

＃題目說明： 
- 在一個 m*n 的矩陣上，只能由左上到右下，二維  gird array 代表走過 (i, j) 時需要的過路費
- 找到一條從 (0,0) 到 (m-1,n-1) 花費最少的路徑

＃ Constraints
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

＃例子
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7

＃想法
用 dp 二維 array 紀錄走到 (i, j) 時最小的花費，dfs 遞迴從 (0,0) 往 (m-1, n-1) 尋找

- 狀態轉移
if(i != m-1 && j != n-1){ 
	dp[i][j] = grid[i][j] + MIN(dfs(m, n, i+1, j, dp, grid), dfs(m, n, i, j+1, dp, grid));
    } else if( j == n-1){ 
        dp[i][j] = grid[i][j] + dfs(m, n, i+1, j, dp, grid);
    } else {
        dp[i][j] = grid[i][j] + dfs(m, n, i, j+1, dp, grid);
    }
 
 -起始狀態 
當在 (m-1, n-1)
if(i == m-1 && j == n-1) {
    dp[i][j] = grid[i][j];
}
    

    


 


