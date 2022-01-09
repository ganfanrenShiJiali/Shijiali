//我的解法
class MyLinkedList {
public:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(NULL) {}
    };
    ListNode* head;
    int size;
    MyLinkedList(){
        head=new ListNode(0);
        size=0;
    }    
    int get(int index) {
        int i=0;
        ListNode* p=head;
        if(index<0 || index>size-1)
        {
            return -1;
        }
        while(i<=index)
        {
            p=p->next;
            i++;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode* pos=new ListNode(val);
        pos->next=head->next;
        head->next=pos;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        ListNode* pos=new ListNode(val);
        p->next=pos;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        if(index<0) addAtHead(val);
        else if(index==size) addAtTail(val);
        else
        {
            ListNode* p=head;
            int i=0;
            while(i<=index-1)
            {
                p=p->next;
                i++;
            }
            ListNode* pos=new ListNode(val);
            pos->next=p->next;
            p->next=pos;
            size++;
        }
    }
    void deleteAtIndex(int index) {
        if(index<0 || index>size-1) return;
        int i=0;
        ListNode* p=head;
        while(i<=index-1)
        {
            p=p->next;
            i++;
        }
        p->next=p->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
