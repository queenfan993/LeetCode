＃難度： Easy

＃題目說明： 
- 給一個 int array nums 和一個目標數字 target
- 回傳在 nums 中任兩個數字合可以等於 target 的 indexes 

＃ Constraints
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- 並且保證一定找得到至少一組解

＃例子
- Input: nums = [2,7,11,15], target = 9
- Output: [0,1]

＃想法
- 使用雙指標前，需要排序，但會造成 index 會跑掉
- 透過一個 struct 來紀錄 index，並排序 sturct array
- 用雙指標從 struct array 的前後開始往中間跑
- 當前後指標相加 > target 就表示前面指標要往後跑一步變大
- 反之亦然
 
＃ 時間複雜度
- O(n)




    


 


