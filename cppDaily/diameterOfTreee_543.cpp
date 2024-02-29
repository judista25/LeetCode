#include <vector>
#include <limits>
#include <iostream>
#include <map>
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
    int max = 0;

public:
    int recursiveGoThrough(TreeNode *root)
    {
        cout << "@" << root->val << " nodes: " << (root->left ? " has left " : " no left ") << (root->left ? " has right " : " no right ") << endl;
        if (!root->right && !root->left)
        {
            cout << "returns:" << 1 << endl;
            return 1;
        }
        if (!root->left)
        {
            int tmp = recursiveGoThrough(root->right);
            cout << "returns:" << tmp << endl;
            return tmp + 1;
        }
        if (!root->right)
        {
            int tmp = recursiveGoThrough(root->left);
            cout << "returns:" << tmp << endl;
            return tmp +1;
        }

        int sum1 = recursiveGoThrough(root->left);
        cout << root->val << "<-@   left value: " << sum1 << " @" << root->left->val << endl;
        int sum2 = recursiveGoThrough(root->right);
        cout << root->val << "<-@   right value: " << sum2 << " @" << root->right->val << endl;
        if (sum1 + sum2 > max)
        {
            // cout<<"change @"<<root->val<<" from:" <<max<< " too ";
            max = sum1 + sum2;
            // cout<<max<<endl;
        }
        if (sum1 > sum2)
            return sum1 + 1;
        return sum2 + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int sum1 = recursiveGoThrough(root);
        sum1--;
        if (sum1 > max)
            return sum1;
        return max;
    }
};