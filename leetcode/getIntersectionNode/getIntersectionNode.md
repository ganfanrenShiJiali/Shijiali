时间复杂度：O(m+n)

空间复杂度：O(m) 哈希表中存了headA链表的结点

**更优解法思路**  
指针 pA 指向 A 链表，指针 pB 指向 B 链表，依次往后遍历
如果 pA 到了末尾，则 pA = headB 继续遍历
如果 pB 到了末尾，则 pB = headA 继续遍历
比较长的链表指针指向较短链表head时，长度差就消除了

有交点，在相交点相等

无交点，均为空是相等

时间复杂度：O（m+n）

空间复杂度：O（1）
