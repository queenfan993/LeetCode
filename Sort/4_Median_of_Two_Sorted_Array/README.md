＃難度： Hard

＃題目說明： 
- 給兩個 int sorted array，找到兩 array 的共同中位數
- 需要在 O(log(m + n)) 裡面完成

＃例子
- Input: nums1 = [1,3], nums2 = [2]
- Output: 2.00000
- Explanation: merged array = [1,2,3] and median is 2.

＃ Constraints
- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -106 <= nums1[i], nums2[i] <= 106



＃想法
- 計算中位數的 index k = (nums1Size + nums2Size + 1)/2
- k 要分成奇數偶數判斷，如果總長度是奇數那中位數的 index 是 k，如果總長偶數，中位數是 (nums[k-1] + nums[k]) /2
- 讓 array1 長度總是小於等於 array 2 (因為後面的判斷有可能會超出陣列範圍)
- 假如從 arry1 找到 index m1，怎麼取出一組 (x, y) = (x, k - x), 讓 k 剛好是中位數的位置
```
nums1
0 1 2 3 ... (m1 - 1), m1, ....

nums2
0 1 2 3 ... (m2 - 1), m2, ....
```
- 所以當總長度是奇數時，中位數的候選會是 nums1[m1-1] 或者 nums2[m2-1]
- 而總長度是偶數時，左中位數的候選是 m1-1 和 m2-1，右中位數的候選是 m1 和 m2
- 那想找到理想的 m1，表示 nums1[m1] 和 nums2[m2-1] 足夠靠近
- 所以當 nums1[m1] < nums2[m2-1] 時，m1 應該要往右找，反之，往左找，
- 用兩個指標 l, r 逼近找到正確的 m1 位置
```
while (l < r) {
		//middle of (l, r)
        const int m1 = l + ((r - l) / 2); 

        //m2 is the index
        const int m2 = k - m1; 

        //compare with 	
        if (nums1[m1] < nums2[m2 - 1])
            l = m1 + 1; 
        else
            r = m1; //re-define the limit，nums[m1] > nums[m2-1]
    }
```
- 最後就是透過候選的方式找到正確的數值

＃ 時間複雜度
- 在比較短的 array 找，並且二元搜尋
- O(log(min(numsSize1, numsSize2)))





    


 


