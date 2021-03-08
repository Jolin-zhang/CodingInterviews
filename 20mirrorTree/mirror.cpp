#include <iostream>

using namespace std;

 struct TreeNode 
 {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) 
    {
        if(pRoot == NULL)
        {
            return NULL;
        }
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};