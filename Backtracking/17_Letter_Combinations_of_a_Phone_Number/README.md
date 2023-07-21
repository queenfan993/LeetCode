＃難度： Medium

＃題目說明： 
- 給一個一個輸入 string, 代表傳統電話上面的按鈕 2 ~ 9，例如 "23"
- 按照號碼的對應表從 2 ~ 9 分別對應的英文字母如下 
- {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
- 回傳輸入電話號碼 string，所能形成的所有英文字母排列

＃例子
- Input: digits = "23"
- Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]]

＃ Constraints
- 0 <= digits.length <= 4
- digits[i] is a digit in the range ['2', '9'].


＃想法
- 其實跟 46 的 permutation 方法差不多，但是需要增加 number 轉換成英文字母的判斷
- 並且因為要處理可能是連續相同的號碼，例如 "22"，hash 的判斷要用減的





    


 


