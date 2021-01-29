#include <iostream>

using namespace std;

class Solution 
{
public:
    int jumpFloor(int number) 
    {
        //列树状图发现规律符合Fibonacci数列
        int f = 0, g = 1;
        //数列的比Fibonacci数量右移一位
        int num = number+1;
        while(num--)
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
    for (int i = 1; i <6; i++)
    {
        cout << solu.jumpFloor(i) <<endl;
    }
    return 0;
}


