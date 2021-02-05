#include <iostream>

using namespace std;

class Solution
{
public:
    double Power(double base, int exponent)
    {   
        double val = 1.0, exp = 0;
        if(exponent < 0)
        {
            if(base == 0)
            {
                return -1;//分母不能为0
            }
            exp = -exponent;
        }
        else if(exponent > 0)
        {    
            exp = exponent;
        }
        else
        {
            return 1;    
        }
        while(exp != 0)
        {
            val *= base;
            exp -= 1;
        }
        return (exponent >= 0)?val:(1/val);
    }
};

int main()
{
    Solution solu;
    cout << solu.Power(2, -3) << endl;
}
