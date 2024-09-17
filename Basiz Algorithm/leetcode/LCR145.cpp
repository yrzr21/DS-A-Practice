#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool checkSubtree(TreeNode *l, TreeNode *r)
    {
        if (l == nullptr & r == nullptr)
            return true;
        else if ((l == nullptr ^ r == nullptr) || (l->val != r->val))
            return false;
            
        return checkSubtree(l->left, r->right) && checkSubtree(l->right, r->left);
    }

    bool checkSymmetricTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        return checkSubtree(root->left, root->right);
    }
};

int main()
{
}
