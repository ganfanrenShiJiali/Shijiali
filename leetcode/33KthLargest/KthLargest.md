Topk问题：在数组中，找到最大的k个数

一、**排序**：先排序，取出最大的k个 时间复杂度：O（n$\log$ n)

二、局部排序：冒泡排序，只冒k个泡 时间复杂度：O（n*k)

三、堆：

思路：只找到Topk，不排序Topk

先用前k个元素生成一个**小顶堆**，<font color="red">小顶堆用于存储当前最大的k个元素</font>

从第k+1个元素开始遍历，和堆顶元素比较，如果大于就替换，并调整堆，保证小顶堆的k个元素总是最大的k个元素

时间复杂度：O（n*$\log$ k)

四、随机选择

<font color="red">分治法：把一个大的问题，转化为若干个子问题（Divide），每个子问题“**都**”解决，大的问题便随之解决。</font>

<font color="red">减治法：把一个大的问题，转化为若干个子问题（Reduce），这些子问题中“**只**”解决一个，大的问题便随之解决。</font>

二分查找是一个典型运用减治法思想的例子

找到数组第k大的数，运用快速排序partition



> 再回过头来看看**第一次**partition，划分之后：
>
> i = partition(arr, 1, n);

- 如果i大于k，则说明arr[i]左边的元素都大于k，于是只递归arr[1, i-1]里第k大的元素即可；
- 如果i小于k，则说明说明第k大的元素在arr[i]的右边，于是只递归arr[i+1, n]里第k-i大的元素即可；



<img src="C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220103212749642.png" alt="image-20220103212749642" style="zoom:67%;" />
