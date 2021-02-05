#include <iostream>

using namespace std;
//不断清除n的二进制表示中最右边的1，同时累加计数器，直至n为0

/*
为什么n &= (n – 1)能清除最右边的1？因为从二进制的角度，n相当于在n - 1的最低位加1。
举例，8（1000）= 7（0111）+ 1（0001），所以8 & 7 = （1000）&（0111）= 0（0000）,
清除了8最右边的1（其实就是最高位的1，因为8的二进制中只有一个1）。
再比如7（0111）= 6（0110）+ 1（0001），所以7 & 6 = （0111）&（0110）= 6（0110），
清除了7的二进制表示中最右边的1（也就是最低位的1）。
 */
class Solution 
{
public:
     int  NumberOf1(int n) 
     {
         int cnt = 0;
         while(n!=0)
         {
             cnt++;
             n = n & (n - 1);
         }
         return cnt;    
     }
};

int main()
{
    Solution solu;
    cout << solu.NumberOf1(10) << endl;
}


