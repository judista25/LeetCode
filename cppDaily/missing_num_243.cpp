#include <vector>
#include <limits>
#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if(i!= nums[i])
            {
                return i;
            }
        }
         return nums.size();
    }
};

int main(void)
{
    Solution sol;
    vector<int> test = {1, 20, 2, 10, 3, 5, 4, 9, 6, 8};
    cout << sol.missingNumber(test) << endl;
}
