#include <iostream>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) 
    {
        //动态规划
        //递归树每一级只用到其前面的两个数，所以只需要两个临时变量
        int f = 0, g = 1;
        while(n--)
        {
            f += g;
            g = f - g;
        }  
        return f;
    }
};



int main()
{
    Solution solu;
    cout << solu.Fibonacci(5) << endl;
}
