#include <iostream>

using namespace std;

class Solution 
{
public:
    int rectCover(int number) 
    {   
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
