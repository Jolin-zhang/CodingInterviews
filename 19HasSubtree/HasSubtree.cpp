#include <iostream>

using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {}
};
class Solution 
{
    bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL)
            return false;
        if(pRoot2->val == pRoot1->val)
        {
            return isSubTree(pRoot1->left, pRoot2->left)
                && isSubTree(pRoot1->right, pRoot2->right);
        }
        else
        {
            return false;
        }
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) 
    {
        if(pRoot1 == NULL || pRoot2 == NULL)
        return false;
        return isSubTree(pRoot1, pRoot2) || 
            HasSubtree(pRoot1->left, pRoot2) ||
            HasSubtree(pRoot1->right, pRoot2);
    }
};
