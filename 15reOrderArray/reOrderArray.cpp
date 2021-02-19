#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) 
    {
        int i = 0;
        for(int j = 0; j < array.size(); ++j)
        {
            if(array[j]&1)
            {
                int temp = array[j];
                for(int k = j-1; k >= i; k--)
                {
                    array[k+1] = array[k];
                }
                array[i++] = temp; 
            }
        }
    }
};

int main()
{
    Solution solu;
    int a[] = {2,3,7,1,6,4};
    vector<int> b1(a, a+6);
    solu.reOrderArray(b1);
    
    for (int i = 0; i < 6; i++)
    {
        cout << b1[i] << ' ';
    }
}