#include <iostream>
#include <vector>

using namespace std;

//调试开关
#define __tmain main

#ifdef __tmain
#define dout cout
#else
#define dout 0 && cout
#endif

#ifdef __tmain
struct ListNode
{
public:
 int val;
  struct ListNode *next;
};  
#endif

class Solution
{
public:

 vector<int> res;
 vector<int> printListFromTailToHead(ListNode* head)
 {   
     if (head != NULL)
     {
         printListFromTailToHead(head->next);
         res.push_back(head->val);
     }
     return res;
 }
};

int __tmain()
{
    ListNode list[4];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = NULL;

    Solution solu;
    vector<int> res = solu.printListFromTailToHead(list);
    for (int i = 0 ; i< res.size() ; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
