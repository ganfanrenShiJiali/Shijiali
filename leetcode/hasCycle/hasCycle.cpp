//哈希表遍历
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef struct ListNode* Position;
class Solution {
public:
    bool hasCycle(ListNode *head) {
       unordered_set<Position>pass;
       while(head)
       {
            if(pass.count(head))
                return true;
            pass.insert(head);
            head=head->next;
       }
       return false;
    }
};

//快慢指针
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;//不能将快慢指针同时初始化为head，否则不会进入while循环
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
