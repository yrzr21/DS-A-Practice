#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        else if (root == p || root == q)
            return root;

        TreeNode *l, *r;
        l = lowestCommonAncestor(root->left, p, q);
        r = lowestCommonAncestor(root->right, p, q);
        if (l != nullptr && r != nullptr)
            return root;
        else if (l != nullptr & r == nullptr)
            return l;
        else if (l == nullptr & r != nullptr)
            return r;
        else
            return nullptr;
    }
};

int main()
{
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};