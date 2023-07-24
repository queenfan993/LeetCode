＃難度： Medium

＃題目說明： 
- 要搶劫房屋，但不能搶劫相鄰的兩間房，並且想辦法搶最多
- nums array 代表房屋的順序和搶劫能得到的價值

＃例子
Input: nums = [2,7,9,3,1]
Output: 12

＃constraints
- 1 <= nums.length <= 100
- 0 <= nums[i] <= 400

＃想法
- 用 dp array index n 儲存表示不管搶不搶 n ，在 n 時能夠獲得的最大價值
- 起始狀態 
    dp[0] = nums[0];
    dp[1] = MAX(nums[0], nums[1]); 
- 狀態轉移
    dp[i] = MAX(nums[i]+dp[i-2], dp[i-1]);




 


