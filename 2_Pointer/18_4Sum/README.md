＃難度： Medium

＃題目說明： 
- 給一個 int array nums 和一個目標數字 target
- 回傳在 nums 中任 4 個數字合可以等於 target 
- 4 個數字的 indexes 要不同 

＃ Constraints
- 1 <= nums.length <= 200
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9


＃例子
- Input: nums = [1,0,-1,0,-2,2], target = 0
- Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

＃想法
- 想要跑過所有組合，但是使用 4 個迴圈會 TLE
- 雙指標至少可以減少一層迴圈
 
＃ 時間複雜度
- O(n^3)




    


 


