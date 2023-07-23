＃難度： Medium

＃題目說明： 
- 給一個 int nums array, 回傳所有排列組合 

＃ Constraints
- 1 <= nums.length <= 6
- -10 <= nums[i] <= 10

＃例子
- Input: nums = [1,2,3]
- Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

＃想法
- 透過遞迴，每個 level (curSize) 判斷 hash table 裡面有沒有包含
- 如果以上面的例子來討論，遞迴的順序會像是，
level 1   i = 1							hash = {1}			
level 2   i = 2 (i = 1 continue )		hash = {1, 2}				
level 3   i = 3 (i = 1, 2 continue)		hash = {1, 2, 3}		
level 3   i = 3 pop hash 3        		hash = {1, 2}        	
level 2   i = 2 pop hash 2    			hash = {1}			
level 2   i = 3			        		hash = {1, 3}
level 3   i = 2 						hash = {1, 3, 2}
level 3	  i = 2	pop hash 2				hash = {1, 3}
level 2   i = 3 pop hash 3				hash = {1}
level 1   i = 1 pop hash 1				hash = {}

level 1	  i = 2
.
.
.
大致流程就是這樣
每次 level 3 的時候要把答案加進 res 裡面

＃ 時間複雜度
- O(n * n!)




    


 


