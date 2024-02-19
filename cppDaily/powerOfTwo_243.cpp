#include <vector>
#include <limits>
#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // on larger scale faster
        
        bitset<sizeof(long int) * 8> binaryRepresentation(n);
        cout << binaryRepresentation << endl;
        bool oneFound = false;
        int i = 0;
        if(n<0)
        i = 1;
        for (; i < binaryRepresentation.size(); i++)
        {
            //cout << binaryRepresentation[i];
            if (binaryRepresentation[i] == 1)
            {
                if (oneFound)
                {
                    return false;
                }
                oneFound = true;
            }
        }
        cout << endl;
        if (!oneFound)
            return false;
        return true;
    }
};

// lame solution

class lameSolution
{
public:
    bool isPowerOfTwo(int n)
    {
        for (long int i = 1; i <= n; i *= 2)
        {
            if (n == i)
            {
                // found match
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    cout << sol.isPowerOfTwo(3);

    return 0;
}