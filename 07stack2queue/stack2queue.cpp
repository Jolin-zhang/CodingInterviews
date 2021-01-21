#include <iostream>
#include <stack>

using namespace std;

//调试开关
#define __tmain main
#ifdef __tmain
#define debug cout
#else
#define debug 0 && cout
#endif

//时间复杂度O(n)
//空间复杂度O(1)
class Solution
{
public:
    void push(int node) 
    {
        stack1.push(node);    
    }

    int pop() 
    {
        int temp = 0;
        if(stack2.empty())
        {
            if(!stack1.empty())
            {
                temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
            else
            {
                return -1;//没有元素可以出队
            }
        }
        temp = stack2.top();
        stack2.pop();
        return temp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int __tmain()
{
    Solution solu;
    solu.push(1);  
    solu.push(2);
    solu.push(3);
    solu.push(4);
     
    int node;
    for(int i=0; i < 6; i++)
    {
        cout << solu.pop() << endl;
    }
    return 0;
}
