//C语言暴力解法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* Position;
typedef struct ListNode* List;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    List listSum=malloc(sizeof(struct ListNode));
    Position p1,p2;
    Position p;
    p1=list1;
    p2=list2;
    p=listSum;
    listSum->next=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->val<p2->val)
        {
            Position pos=malloc(sizeof(struct ListNode));
            pos->val=p1->val;
            pos->next=NULL;
            p->next=pos;
            p=p->next;
            p1=p1->next;
        }
        else if(p1->val>p2->val)
        {
            Position pos=malloc(sizeof(struct ListNode));
            pos->val=p2->val;
            pos->next=NULL;
            p->next=pos;
            p=p->next;
            p2=p2->next;
        }
        else
        {
            Position pos1,pos2;
            pos1=malloc(sizeof(struct ListNode));
            pos2=malloc(sizeof(struct ListNode));
            pos1->val=p1->val;
            pos2->val=p2->val;
            p->next=pos1;
            pos1->next=pos2;
            pos2->next=NULL;
            p=p->next;
            p=p->next;
            p1=p1->next;
            p2=p2->next;
        }
    }
    if(p1!=NULL)
    {
        while(p1!=NULL)
        {
            Position pos=malloc(sizeof(struct ListNode));
            pos->val=p1->val;
            pos->next=NULL;
            p->next=pos;
            p=p->next;
            p1=p1->next;
        }
    }
    if(p2!=NULL)
    {
        while(p2!=NULL)
        {
            Position pos=malloc(sizeof(struct ListNode));
            pos->val=p2->val;
            pos->next=NULL;
            p->next=pos;
            p=p->next;
            p2=p2->next;
        }
    }
    return listSum->next;
}
-----------------------------------------------------------------------------------------------
//C语言暴力解法改进：迭代解法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* Position;
typedef struct ListNode* List;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    List listSum=malloc(sizeof(struct ListNode));
    Position prev;
    prev=listSum;
    while(list1!=NULL && list2!=NULL)
    {
        if(list1->val<list2->val)
        {
            prev->next=list1;
            list1=list1->next;
        }
        else
        {
            prev->next=list2;
            list2=list2->next;
        }
        prev=prev->next;
    }
    prev->next=list1==NULL?list2:list1;
    return listSum->next;
}
-----------------------------------------------------------------------------------------------------------------
//递归解法
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* Position;
typedef struct ListNode* List;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    if(list1->val<list2->val)
    {
        list1->next=mergeTwoLists(list1->next,list2);
        return list1;
    }
    else
    {
        list2->next=mergeTwoLists(list2->next,list1);
        return list2;
    }    
}
