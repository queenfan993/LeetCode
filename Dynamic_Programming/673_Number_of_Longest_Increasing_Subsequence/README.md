＃難度： Medium

＃題目說明： 
- 給定一個數字 array nums, 找到最長不遞減 subsequence，回傳有多少個  subsequence 跟最長長度一樣長

＃ Constraints
- 1 <= nums.length <= 2000
- -10^6 <= nums[i] <= 10^6

＃例子
- Input: nums = [1,3,5,4,7]
- Output: 2 (1357 和 1347) 共兩組符合

＃想法
- 使用 dp array 紀錄在  i 位置的子序列最長是多少
- 使用 cnt array 紀錄在  i 位置符合目前最長子序列的個數
- 從 i = 0 然後 j = 0 ~ i 開始掃， 檢查 nums[i] 可以加在哪個 nums[j]後面 
- 如果符合 nums[i] > nums[j] 就可以判斷狀態轉移 
- 起始狀態，至少自己都要是一個 subsequence
```
for(int i = 0; i <= numsSize; i++){
    dp[i] = 1;
    cnt[i] = 1;
}
```
- 狀態轉移
```
if(dp[j] +1 > dp[i]) { // 應該要更新
    dp[i] = dp[j] + 1 
}
```

＃ 時間複雜度
- 因為使用兩個迴圈 i = 0 ~ n 和 j < i 近似於  n(n+1)/2
- O(n^2)



    


 


