#include <iostream>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {} //结构体构造函数初始化
};

class Solution 
{
public:
    ListNode* ReverseList(ListNode* pHead) 
    {
        if(pHead == NULL)
        {
            return NULL;
        }
        ListNode *reversedHead = NULL;
        ListNode *current = pHead;
        ListNode *temp = NULL;
        ListNode *pre = NULL;
        
        while(current != NULL)
        {
            temp = current->next;
            current->next = pre;
            if(temp == NULL)
            {
                reversedHead = current;
            }
            pre = current;
            current = temp;
        }
        return reversedHead;
    }
};
int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    Solution solu;
    cout << solu.ReverseList(node1)->val << endl;
    return 0;
}
