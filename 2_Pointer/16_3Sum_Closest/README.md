＃難度： Medium

＃題目說明： 
- 給一個 int array nums 和一個目標數字 target
- 回傳在 nums 中三個數字合最接近 target 的數字合 

＃ Constraints
- 3 <= nums.length <= 500
- -1000 <= nums[i] <= 1000
- -10^4 <= target <= 10^4

＃例子
- Input: nums = [-1,2,1,-4], target = 1
- Output: 2

＃想法
- 先 sort nums
- 用一個迴圈從 i = 0 開始，在迴圈中每次都有兩個指標
- 從 i + 1 和 length - 1 開始往中間
- 判斷三數是否大於小於 target，小於就移動左指標向右，反之亦然
 
＃ 時間複雜度
- O(n^2) 兩層迴圈




    


 


