＃難度： Easy

＃題目說明： 
- 給一個 array nums 和一個 val，把 nums 中，所有 val 移到最後並且回傳除了 val 外的值有多少個

＃ Constraints
- 0 <= nums.length <= 100
- 0 <= nums[i] <= 50
- 0 <= val <= 100

＃例子
- Input: nums = [0,1,2,2,3,0,4,2], val = 2
- Output: 5, nums = [0,1,3,0,4,2,2,2]

＃想法
- 由左而右遍歷 nums 
- 用 count 紀錄目前遇到的指定 val 共有多少個
- 如果遇到的元素非 val 那就和往前數 count 的元素交換 (往前數 count 的元素數值是 val)

＃ 時間複雜度
- O(n)




    


 


