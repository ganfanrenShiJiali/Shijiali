//我的解法
typedef struct ListNode* Position;
typedef struct ListNode* List;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int n=0;
    List sum=l1;
    Position pre=NULL;
    while(l1!=NULL && l2!=NULL)
    {
        int value=l1->val;
        l1->val=(value+l2->val+n)%10;
        n=(value+l2->val+n)/10;
        pre=l1;
        l1=l1->next;
        l2=l2->next;
    }
    while(l1!=NULL)
    {
        if(n==0)
            break;
        int value=l1->val;
        l1->val=(value+n)%10;
        n=(value+n)/10;
        pre=pre->next;
        l1=l1->next;
    }
    if(l2!=NULL)
    {
        pre->next=l2;
        if(n==0)
            return sum;
        while(l2!=NULL)
        {
            int value=l2->val;
            l2->val=(value+n)%10;
            n=(value+n)/10;
            l2=l2->next;
            pre=pre->next;
        }
    }
    if(n!=0)
    {
        Position pos=malloc(sizeof(struct ListNode));
        pos->val=n;
        pos->next=NULL;
        pre->next=pos;
    }
    return sum;
}

//官方解法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
