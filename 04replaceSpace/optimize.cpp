#include <iostream>

using namespace std;

class Solution 
{
public:
    void replaceSpace(char *str,int length) 
    {
         if (str == NULL || length <= 0) return; //判空
         int cnt = 0;  // 空格的个数
         for (int i=0; i != length; ++i) 
         {
             if (str[i] == ' ') ++cnt;
         }
         if (!cnt) return; // 没有空格，直接返回
         int new_length = length + cnt * 2;
         for (int i = length; i >= 0; --i) 
         {
             if (str[i] == ' ') 
             {
                 str[new_length--] = '0';
                 str[new_length--] = '2';
                 str[new_length--] = '%';
             }
             else 
             {
                 str[new_length--] = str[i];
             }
         }
     }
};

int main()
{
    char str[10+1] = "a b c d";
    Solution solu;
    solu.replaceSpace(str, 10);

    cout << str << endl;
    return 0;
}
