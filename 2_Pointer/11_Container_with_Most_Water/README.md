＃難度： Medium

＃題目說明： 
- 有一個水槽每個單位間隔都有立一個擋板，高 height[i]
- 水槽共長 heightSize
- 求出能裝最多水的兩個擋板，回傳水的容量(底*高)
- 如果找到的兩個檔板是 x, y
- 則可以裝水 min(height[x], height[y]) * (y-x)

＃ Constraints
- n == height.length
- 2 <= n <= 10^5
- 0 <= height[i] <= 10^4

＃例子
- Input: height = [1,8,6,2,5,4,8,3,7]
- Output: 49
- 以 8 和 7 這兩個擋板能形成長 7 的底
- 得出 min(8,7) * 7 = 49

＃想法
- 左右端指標 i, j，朝向中間移動
- 比較 height[i] 和 height[j] 每次迴圈看誰比較小，就調整誰
- 每次迴圈都紀錄當下最大值
  
＃ 時間複雜度
- 遍歷一次 O(n)




    


 


