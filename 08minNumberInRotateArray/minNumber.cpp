#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) 
    {
        if(rotateArray.size() == 0)
        {
            return 0;
        }

        int left = 0, mid = 0, right = rotateArray.size() - 1;
        //rotateArray[left] >= rotateArray[right]确保旋转
        while(rotateArray[left] >= rotateArray[right])
        {   
            if(right - left == 1)
            {  
                mid = right; 
                break;
            }
            mid = (left + right)/2;
            //otateArray[left]、rotateArray[mid]、rotateArray[right]相等， 只能顺序查找
            if(rotateArray[left] == rotateArray[mid] && rotateArray[right] == rotateArray[mid])
            {
                return MinOrder(rotateArray, left, right);
            }
            //中间元素位于前面的递增子数组,此时最小元素位于中间元素的后面
            if(rotateArray[mid] >= rotateArray[left])
            {
                left = mid;
            }
            //中间元素位于后面的递增子数组,此时最小元素位于中间元素的前面
            else
            {
                right = mid;
            }
        }
        return rotateArray[mid];
    }
private:
    //顺序寻找最小值
    int MinOrder(vector<int> &num, int left, int right)
    {
        int result = num[left];
        for(int i = left+1; i < right; i++)
        {
            if(num[i] < result);
            {
                result = num[i];
            }
        }
        return result;
    }
};

int main()
{
    Solution solu;
    //vector<int> num = {4, 5, 6, 1, 2, 3};
    vector<int> num = {2, 2, 2, 2, 0, 2};
    int result = solu.minNumberInRotateArray(num);
    cout << result << endl;
    return 0;
}

















