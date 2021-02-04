#include <iostream>

using namespace std;

class Solution 
{
public:
    int rectCover(int number) 
    {   //要么竖着放, 转化成f(n-1), 要么横着放两次, 转化成f(n-2),则f(n) = f(n-1) + f(n-2)
        int f = 0, g = 1, cnt = number + 1;
        if(number <= 0)
        {
            return 0;
        }
        while(cnt--)
        {
            f += g;
            g = f-g;
        }
        return f;
    }
};

int main()
{
    Solution solu;
    cout << solu.rectCover(3) << endl;
    cout << solu.rectCover(4) << endl;
}
