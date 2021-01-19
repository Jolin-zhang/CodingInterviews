#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    bool Find(vector<vector<int> > array,int target)
    {
        int row = 0, col = 0;
        bool isFound = false;

        for(int row = 0; row < array.size() ; ++row)
        {
            for(int col = 0; col < array[row].size(); ++col)
            {
                if (false == isFound && target == array[row][col])
                {
                    isFound = true;
                }
            }
        }
        return isFound;
     }

 };

int main()
{
    int a1[] = { 1, 2,  8,  9,};
    int a2[] = { 2, 4,  9, 12,};
    int a3[] = { 4, 7, 10, 13,};
    int a4[] = { 6, 8, 11, 15,};
    vector<vector<int> > array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));

    Solution solu;
    cout <<solu.Find(array,9) <<endl;
    return 0;
}


