＃難度： Medium

＃題目說明： 
- 給定一個 string s, 回傳最長的重複回文 char * , 例如 abba 是一個回文

＃ 例子
- Input: s = "cbbd"
- Output: "bb"

＃ Constraints
- 1 <= s.length <= 1000
- s consist of only digits and English letters.


＃想法 (Manacher)
- 先做預處理在原字串 s 每個字符前後都加上 # 形成 pre 新字串
```
 s    =   C   B   B   D   
 pre  = # C # B # B # D # 
 dp   = 0 1 0 1 2 1 0 1 0
```
- dp[i] 定義為，在 pre 上，由中心擴散可以找到的對稱數量
- 然後考慮迴圈 index i = 0 開始由左向右跑，
- 用 maxRight 表示目前已知的對稱最右, center 表示 maxRight 的鏡像中心
- 也可以換句話說 dp[center] = len(right - center);
```

--------left-------center-------right------------------
						     ^
						     |
						   當前的 i 可能在這
```
- 當 i >= maxRight 時，必須中心擴散找 dp[i] 的值
- 當 i < maxRight 時，dp[i] 想更新時有三種情況
1. dp[mirror] < maxRight - i 時，表示 dp[i] 可以照抄 dp[mirror]，因為 mirror 上面的回文還沒超過現在已知範圍
2. dp[mirror] == maxRight - i 時，表示 dp[i] 要繼續往下找，必須更新 maxRight，且當個迴圈可以先 dp[i] = dp[mirror]
3. dp[mirrot] > maxRight - i 時，肯定不能照抄，只能先取 dp[i] = maxRight - i
```
合併成表達式更新， dp[i] = min(p[mirror], maxRight - i)
```
- dp 找完，就差不多了


＃想法 (動態規劃)
- 使用二維 dp array 紀錄起始  i 到 j 的回文長度是不是最長，如果是那就紀錄 i 和 j 
- 從	 i = 2 和  j < i , dp[j][i] 慢慢填   
- 起始狀態，需要先填好 dp[0][0] 、dp[0][1] 、dp[1][1]   
- 狀態轉移
```
if(s[i] == s[j] && dp[j+1][i-1]!= -1){
   dp[j][i] = dp[j+1][i-1]+2;
} 
```


＃ 時間複雜度
- Manacher's algorithm 是最佳解，O(n)，迴圈中 i 始終向右，直到結束
- 那如果是動態規劃，使用兩個迴圈 i = 2 ~ n 和 j < i 近似於  n(n+1)/2, 
- O(n^2)



    


 


