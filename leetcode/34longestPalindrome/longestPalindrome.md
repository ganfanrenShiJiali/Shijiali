**暴力解法：**  

时间复杂度：O（n^3^）

空间复杂度：O（1）

**动态规划**：（比起中心扩散耗时更长）

得知：一个以i,j为左右边界的子串是否是回文子串由s[i]==s[j]和i+1,j-1是否是回文子串决定

定义dp [ i ] [ j ] 表示是否以i,j为边界的子串是否是回文子串，得：

dp [ i ] [ j ] = s[ i ] == [ j ] and dp [ i+1 ] [ j-1 ] 

有边界条件，若 j - 1 - ( i+1)+1<2，得j-i<3

dp[ i ] [ i ] 一定为true，每个值根据左下角的值，可以一列一列填数组

<img src="C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220104200036273.png" alt="image-20220104200036273" style="zoom:67%;" />

时间复杂度：O（n^2^）

空间复杂度：O（n^2^）

**中心扩散法**：

暴力解法是枚举子串的左右边界，而中心扩散是枚举子串的中心位置

分为两种情况，对于奇数子串，子串中心是一个字符，对于偶数子串，子串中心是相邻的两个字符

定义一个函数判断传入的子串中心能构成回文子串的最大长度
