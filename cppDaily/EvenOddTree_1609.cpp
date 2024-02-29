#include <vector>
#include <iostream>
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
    bool isEvenOddTree(TreeNode *root)
    {
        vector<TreeNode *> q;
        int levelChildren = 0;
        int nextChildren = 0;
        int levelCount = 0;
        int levelMax = 0;
        int levelMin = INT32_MAX;
        if (!root)
            return true;
        if(!(root->val%2))
            return false;
        if (root->left)
        {
            q.push_back(root->left);
            levelChildren++;
        }
        if (root->right)
        {
            q.push_back(root->right);
            levelChildren++;
        }
        int level = 1;
        for (int i = 0; i < q.size(); i++)
        {
            levelCount++;
            // cout<<levelChildren <<" vs "<<levelCount<<endl;
            if (level % 2)
            {
                if ((q[i]->val % 2))
                    return false;
                cout<<"Odd compare: "<<level<<" | "<<q[i]->val<<" vs "<<levelMin<<" | "<<endl;                // odd
                if (q[i]->val >= levelMin)
                    return false;
                levelMin = q[i]->val;
            }
            else
            {
                if (!(q[i]->val % 2))
                    return false;
                cout<<"Even compare: "<<level<<" | "<<q[i]->val<<" vs "<<levelMax<<" | "<<endl;
                //  even
                if (q[i]->val <= levelMax)
                    return false;
                levelMax = q[i]->val;
            }
            if (q[i]->left)
            {
                // cout<<"adding child @"<<level<<endl;
                q.push_back(q[i]->left);
                nextChildren++;
            }
            if (q[i]->right)
            {
                // cout<<"adding child @"<<level<<endl;
                q.push_back(q[i]->right);
                nextChildren++;
            }

            if (levelCount == levelChildren)
            {
                cout << "End of level: " << levelChildren << " max and min: " << levelMax << " | " << levelMin << endl;
                // next level
                level++;
                levelCount = 0;
                levelMax = 0;
                levelMin = INT32_MAX;
                // set next level breakpoint
                levelChildren = nextChildren;
                nextChildren = 0;
            }
        }
        return true;
    }
};