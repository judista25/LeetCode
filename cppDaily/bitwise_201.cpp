#include <vector>
#include <limits>
#include <iostream>
#include <map>
using namespace std;

ostream &operator<<(std::ostream &os, const std::vector<int> &vec)
{
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        os << vec[i];
        if (i < vec.size() - 1)
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
};

class superSolution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int cnt = 0;
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        return (left << cnt);
    }
};

// tachy solution
class Solution
{
public:
    int rangeBitwiseAnd(long int left, long int right)
    {
        if (left == 1073741824)
            return 1073741824;
        long int result = left;
        for (long int i = left + 1; i <= right; i++)
        {
            result = result & i;
            if (result == 0)
                return 0;
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    // vector<int> test = {1, 20, 2, 10, 3, 5, 4, 9, 6, 8};
    cout << sol.rangeBitwiseAnd(1073741824, 2147483647) << endl;
}
