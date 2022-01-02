**KMP算法**

假设匹配串为：ababc

**第一步**找出匹配串的所有前缀

a

ab

aba

abab

ababc

**第二步：**找出所有子串的**最大公共前后缀**(红字为最大公共前后缀的长度)

<font color="red">0</font>	a	第一个前缀固定为0

<font color="red">0</font>	ab

<font color="red">1</font>	aba

<font color="red">2</font>	abab

<font color="red">0</font>	ababc	根据后面，与匹配串相等的不用考虑

整理为前缀表：prefix table

> <font color="red">0	1	2	3	4</font>
>
> a	b	a	b	c
>
> <font color="blue">-1	0	0	1	2</font>	为了方便KMP算法，将前面求得的最大公共前后缀往后挪一位，最前面补-1
