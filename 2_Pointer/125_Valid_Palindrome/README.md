＃難度： Easy

＃題目說明： 
- 給一個 string s，忽略除了英文大小寫和數字外的字符
- 大寫視為小寫
- 根據以上判斷 string 是否為回文

＃ Constraints
- 1 <= s.length <= 2 * 10^5
- s consists only of printable ASCII characters.

＃例子
- Input: s = "A man, a plan, a canal: Panama"
- Output: true

＃想法
- 使用雙指標從左右開始往中間跑，每次遇到非數字英文就跳過
- 判斷雙指標的數值是否相同，如果始終相同，那 string 回文
 
＃ 時間複雜度
- O(n)，就是每個字符都跑過一次




    


 


