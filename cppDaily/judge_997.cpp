#include <iostream>
#include <map>
using namespace std;
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        map<int, pair<int, int>> findMayor;
        for (int i = 0; i < trust.size(); i++)
        {
            findMayor[trust[i][1]].first++;
            findMayor[trust[i][0]].second++;
        }
        for (int i = 0; i < n; i++)
            if (findMayor[i + 1].second == 0 && findMayor[i + 1].first == n - 1)
                return i + 1;
        return -1;
    }
};

class somehowSlowerSolution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        map<int, pair<int, int>> courthouse;
        int judgeIndex = 1;
        for (auto rule : trust)
        {
            courthouse[rule[1]].first++;
            courthouse[rule[0]].second++;
            if (rule[0] == judgeIndex)
            {
                for (int i = 0; i < n; i++)
                {
                    // u trust nobody
                    if (courthouse[judgeIndex + i].second == 0)
                    {
                        judgeIndex += i;
                        break;
                    }
                }
            }
        }
        if (judgeIndex > n || courthouse[judgeIndex].first != n - 1)
            return -1;
        return judgeIndex;
    }
};