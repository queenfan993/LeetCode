＃難度： Medium

＃題目說明： 
- 給定一個只包含英文小寫的 string 和一個 target k
- 找到最長的 sub string 並且裡面出現的元素都要大於等於 k 個

＃ Constraints
- 1 <= s.length <= 10^4
- s consists of only lowercase English letters.
- 1 <= k <= 10^5

＃例子
- Input: s = "ababbc", k = 2
- Output: 5
- ababb 是最長的 substring 符合其中元素都大於 k

＃想法
- 用總共有多少不同小寫字母來跑迴圈 cnt = 1 代表目前 substring 含有一種小寫字母，以此類推
- 每次迴圈用一個 hash 來紀錄 substring 中的各小寫字母數量
- 用 uniqueCnt 代表當下字串的小寫字母字串共有多少種類，必須小於 cnt
- start 表示 substring 起點， end 表示終點，剛開始兩者都在 0
- end 會一直往前走，當 uniqueCnt > cnt 的時候，start 會往前走
- 每走一步 end 判斷 hash 中的小寫字母是不是都大於 k，如果都大於就和當前最大值比較
 
＃ 時間複雜度
- 跑了常數 26 次迴圈，在 26 次中跑了 n 次，並且檢查 hash 也有迴圈
- 所以是 O(cn) = O(n)



    


 


