#include <iostream>
#include <vector>

using namespace std;

#define __tmain main

#ifdef __main 
#define debug cout
#else
#define debug 0 && cout 
#endif

#ifdef __tmain
struct TreeNode
{
    int val;
    TreeNode* left;    
    TreeNode* right;

    TreeNode(int x)
    :val(x), left(NULL), right(NULL)
    {
    }
    
    static void PreOrder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        cout << root->val << endl;
        PreOrder(root->left);	
        PreOrder(root->right);
    }
    
    static void InOrder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        InOrder(root->left);
        cout << root->val << endl;
        InOrder(root->right); 
    }   
 
};
#endif

class Solution
{
public:
    TreeNode* reconstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        int n = pre.size();        
        int m = vin.size();
        if(n != m || n == 0)
        {
            return NULL;
        }
        return construct(pre, vin, 0, n-1, 0, m-1); 
    }
    
    TreeNode* construct(vector<int>& pre, vector<int>& vin, int l1, int r1, int l2, int r2)
    { 
        TreeNode* root = new TreeNode(pre[l1]);
        if(r1 == l1)
        {
            return root;
        }
        int index = 0;
        int val = pre[l1];
        for(index = l2 ; index <=r2 ; index++)
        {
            if(vin[index] == val)
            break;
        }
        int leftTreeLen = index - l2; //l1是先序遍历中第一个元素的序号(l2是中序遍历中第一个元素的序号)
        int rightTreeLen = r2 - index; //r1是先序遍历最后一个元素的序号(r2是中序遍历最后一个元素的序号)
        if(leftTreeLen > 0)
        {
            root->left = construct(pre, vin , l1+1, l1+leftTreeLen, l2, index-1);
        }
        if(rightTreeLen > 0 )
        {
            root->right = construct(pre, vin, l1+1+leftTreeLen, r1, index+1, r2);
        }
        return root;

    }
};

int __tmain()
{
    int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int in[] = {4, 7, 2, 1, 5, 3, 8, 6};
    
    vector<int> preOrder(pre, pre+8);
    vector<int> vinOrder(in, in+8);

    Solution solu;
    TreeNode* root = solu.reconstructBinaryTree(preOrder, vinOrder);

    cout << "preOrder" << endl;
    TreeNode::PreOrder(root);
    //cout << endl;

    cout << "inOrder" << endl;
    TreeNode::InOrder(root);
    //cout << endl;

    return 0;
}

