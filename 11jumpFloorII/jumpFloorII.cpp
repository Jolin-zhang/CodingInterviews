#include <iostream>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) 
    {
        if(number <= 0)
        {
            return -1;
        }
        else if(number == 1)
        {
            return 1;
        } 
     
        else
        {
            return 2*jumpFloorII(number-1);
        }
    }
};

int main()
{
    Solution solu;
    for(int i = 0; i < 6; i++)   
    {
        cout << solu.jumpFloorII(i) << endl;
    }
}
