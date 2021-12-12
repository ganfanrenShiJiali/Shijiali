//我的解法：暴力解法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pos=head;
        int num=0;
        while(pos!=NULL)
        {
            num++;
            pos=pos->next;
        }
        int count=num-n;
        if(count==0)
            return head->next;
        int i;
        pos=head;
        for(i=1;i<num-n;i++)
        {
            pos=pos->next;
        }
        ListNode* posNext=pos->next->next;
        pos->next=posNext;
        return head;
    }
};
