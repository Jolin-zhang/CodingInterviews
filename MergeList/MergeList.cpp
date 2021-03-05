#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {}
};
class Solution 
{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1)
            return pHead2;
        if(!pHead2)
            return pHead1;
        ListNode* Head;
        ListNode* p;
        //取较小值做头结点
        if(pHead1->val <= pHead2->val)
        {
            Head = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            Head = pHead2;
            pHead2 = pHead2->next;
        }
        //开始遍历合并
        p = Head;//p为合并后链表的工作指针
        while(pHead1&&pHead2)
        {
            if(pHead1->val <= pHead2->val)
            {
                p->next = pHead1;
                pHead1 = pHead1->next;
                p = p->next;
            }
            else
            {
                p->next = pHead2;
                pHead2 = pHead2->next;
                p = p->next;
            }
        }
    //链表1遍历完了
    if(pHead1 == NULL)
    {
        p->next = pHead2;
    }
    if(pHead2 == NULL)
    {
        p->next = pHead1;
    }
    return Head;
    }
};


int main()
{
    ListNode *node10 = new ListNode(1);
    ListNode *node11 = new ListNode(3);
    ListNode *node12 = new ListNode(5);
    ListNode *node20 = new ListNode(2);
    ListNode *node21 = new ListNode(4);
    ListNode *node22 = new ListNode(6);

    node10->next = node11;
    node11->next = node12;
    node12->next = NULL;
    node20->next = node21;
    node21->next = node22;
    node22->next = NULL;
    
    Solution solu;
    ListNode *p = solu.Merge(node10, node20);
    while(p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}