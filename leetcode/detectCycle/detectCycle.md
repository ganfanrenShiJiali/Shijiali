找到环形的入口节点

<img src="C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211230201421492.png" alt="image-20211230201421492" style="zoom:67%;" />

假设在进入环形长度b后相遇，快指针已经绕环形走了n圈

2(a+b)=a+n(b+c)+b

得：a=c+(n-1)(b+c)

当快慢指针相遇后，让一个指针从链表指针开始后移，慢指针开始后移，最终会在环形入口点处相遇
