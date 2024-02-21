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
class Solution
{
private:
public:
    bool calculateAndSwitch(int *gameBricks, int gameScore, vector<int> &maxes, int *ladders)
    {
        if (*ladders == 0)
            return false;
        if (!(maxes.empty()) && gameScore <= maxes[0])
            return false;
        if (maxes[0] == -1)
        {
            (*gameBricks) += gameScore;
        }
        else
            (*gameBricks) += gameScore - maxes[0];
        maxes[0] = gameScore;
        sort(maxes.begin(), maxes.end());
        if ((*gameBricks) < 0)
            return false;
        return true;
    }
    
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        vector<int> maxes(ladders, -1);

        int gameBricks = bricks;
        int heightBefore = heights[0];
        int i = 1;
        for (; i < heights.size(); i++)
        {
            cout << "Next stats i: |" << i << "| height now [" << heights[i] << "] and before [" << heightBefore << "]" << endl;
            if (heights[i] <= heightBefore)
            {
                // pass
                cout << "pass" << endl;
            }
            else
            {
                int difference = heights[i] - heightBefore;
                // try using bricks
                gameBricks -= difference;
                cout << "climbing by  " << difference << " bricks: " << gameBricks << endl;
                if (0 < gameBricks)
                {
                    //all good
                }
                else
                {
                    //bricks gone use ladders
                    break;
                }
            }
            cout << "STATS --> bricks left |" << gameBricks << "| --> minMax " << maxes << endl;
            heightBefore = heights[i];
        }
        
        return heights.size() - 1;
    }
};

int main()
{
    Solution sol;
    vector<int> pass = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    cout << sol.furthestBuilding(pass, 10, 2) << endl;
}
