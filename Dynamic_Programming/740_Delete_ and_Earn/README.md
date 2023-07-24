＃難度： Medium

＃題目說明： 
- 給定 nums array，當選定 array 當中的某數  x 時會同時刪除  x+1 和 x-1 (x+1 和  x-1 不一定在 array 裡)
- 選定後得到  x 的價值，問根據該 nums array 能夠得到的最大價值是多少

＃ Constraints
- 1 <= nums.length <= 2 * 10^4
- 1 <= nums[i] <= 10^4


＃例子
- nums = [3, 4, 2] => 6 可選 4(刪除 3 和 5) 和 2(刪除 1 和 3)

＃想法
- 先用內建 qsort 排列，因為取和刪除跟大小有關，順序就不用在用額外的空間來紀錄
- 當有重複的時候，取了重複的一個，等於可以取全部，用 count array （長度 numsSize） 來計算某數總共重複多少 （如果全部都不同的話，各元素都為一，總之總和要是  numsSize）
- 可以把原本 numsSize 的長度，轉換成共有多少相異元素，來當成長度 
- 使用 dp array 表示判斷到第  i 個相異元素時，最大價值是多少 
- 有兩種 index，其一是 nums array 上的，另一種表示是不同元素，在 count 和 dp array 上
- 起始狀態 
```
dp[0] = nums[0]*count[0];
```
```
if(nums[0]+1 != nums[count[0]]){
    dp[1] = dp[0] + nums[count[0]]*count[1];
} else {
    dp[1] = MAX(dp[0], nums[count[0]]*count[1]);
} 
```    
- 狀態轉移
- 當 nums[i] != nums[i-1] 時判斷如果 
1. nums[i-1] == nums[i]-1 表示兩數不能同時選取 （nums[i] 和 nums[i-1]），則狀態轉移如下
```
dp[temp] = MAX(dp[temp-1], dp[temp-2] + (nums[i]* count[temp]));
```
2. 如果不相等，那就表示 dp[temp-1] 也可以被選取，則狀態轉移如下
```
dp[temp] = MAX(dp[temp-1], dp[temp-2]) + (nums[i]* count[temp]);
``` 


    


 


