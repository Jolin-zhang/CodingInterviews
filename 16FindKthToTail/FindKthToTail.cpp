#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {} //结构体构造函数初始化
};

class Solution
{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        ListNode* p;
        ListNode* q;
        int i = k;
        for (p = q = pListHead; p != NULL; p = p->next, i--)
        {
            if (i < 0)
            {
                q = q->next;
            }
        }
        return i <= 0 ? q : NULL;
    }
};
int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    Solution solu;
    cout << solu.FindKthToTail(node1, 3)->val << endl;
    return 0;
}
