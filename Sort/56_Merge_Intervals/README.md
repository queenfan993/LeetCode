＃難度： Medium

＃題目說明： 
- 給一個二維 intervals 陣列，intervals[i] = [起始，終點]
- 當有段落重疊時，要把它合併

＃ Constraints
- 1 <= intervals.length <= 10^4
- intervals[i].length == 2
- 0 <= starti <= endi <= 10^4

＃例子
- Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
- Output: [[1,6],[8,10],[15,18]]

＃想法
- 先用 quicksort 針對 intervals[i][0] 做排序
- 比較每個 intervals[i][0] 和後面的大小看是部分覆蓋還是完全覆蓋

＃ 時間複雜度
- 如果說內建 sort 是 O(nlogn)
- 那本身判斷重疊是一個 O(n)
- 最後時間複雜度是 O(nlogn)



    


 


