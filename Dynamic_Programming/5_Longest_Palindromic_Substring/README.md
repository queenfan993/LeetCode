＃難度： Medium

＃題目說明： 
- 給定一個 string s, 回傳最長的重複回文 char * , 例如 abba 是一個回文

＃ 例子
- Input: s = "cbbd"
- Output: "bb"

＃ Constraints
1 <= s.length <= 1000
s consist of only digits and English letters.



＃想法
- 使用二維 dp array 紀錄起始  i 到 j 的回文長度是不是最長，如果是那就紀錄 i 和 j 
- 從	 i = 2 和  j < i , dp[j][i] 慢慢填   

- 狀態轉移
- if(s[i] == s[j] && dp[j+1][i-1]!= -1){
-   dp[j][i] = dp[j+1][i-1]+2;
- } 
 
- 起始狀態 
- 需要先填好 dp[0][0] 、dp[0][1] 、dp[1][1]   

＃ 時間複雜度
- 使用兩個迴圈 i = 2 ~ n 和 j < i 近似於  n(n+1)/2, 
- O(n^2)



    


 


