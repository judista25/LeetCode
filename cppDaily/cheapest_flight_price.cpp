#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
public:
    int recursePathDFS(int n, vector<vector<int>> &flights, int src, int dst, int k, int from)
    {
        // [[0,1,100],[1,2,100],[0,2,500]]
        if (src == dst)
        {
            return 0;
        }
        if (k == -1)
        {
            return INT32_MAX;
        }
        int min = INT32_MAX;
        for (int i = 0; i < flights.size(); i++)
        {
            if (flights[i][0] == src)
            {
                int tmpSum = recursePathDFS(n, flights, flights[i][1], dst, k - 1, from + 1);
                cout << min << endl;
                if (INT32_MAX == tmpSum)
                    continue;
                if (tmpSum + flights[i][2] < min)
                {
                    min = tmpSum + flights[i][2];
                }
            }
        }
        cout << endl;
        return min;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // dfs
        int returnCode = recursePathDFS(n, flights, src, dst, k, 0);
        return (returnCode == INT32_MAX) ? -1 : returnCode;
    }
};

int main()
{

    Solution sol;
    vector<vector<int>> test = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    cout << sol.findCheapestPrice(3, test, 0, 2, 1) << endl;
}