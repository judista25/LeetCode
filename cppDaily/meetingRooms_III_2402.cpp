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
ostream &operator<<(std::ostream &os, const std::vector<std::vector<int>> &vecOfVec)
{
    os << "[";
    for (size_t i = 0; i < vecOfVec.size(); ++i)
    {
        os << vecOfVec[i];
        if (i < vecOfVec.size() - 1)
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
};

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        // prep part
        vector<vector<int>> rooms(n, vector<int>{0, 0}); // start end

        vector<int> counter(n, 0);
        int delay = 0;

        int minTime = numeric_limits<int>::max();
        int runTimeMinTime = minTime;

        bool seated = false;
        int initialIndex = 0;

        sort(meetings.begin(), meetings.end()); // make sure meetings are sorted so i can just pop
        cout << meetings << endl;
        for (int i = 0; i < meetings.size(); i++)
        {
            seated = false;
            cout << "IN " << meetings[i] << " runtime minTime: " << runTimeMinTime << " ";

            for (int j = 0; j < n; j++)
            {
                // cout<< "testing No:"<<i<<"vs:"<<j<<" |||| " <<rooms[j][1]<<" vs "<<meetings[i][0]<<"  minTime:" << minTime <<"  | "<< meetings[i][0]<<endl;
                if ((rooms[j][0] == 0 && rooms[j][1] == 0) || (rooms[j][1] <= meetings[i][0] && runTimeMinTime <= meetings[i][0]))
                {
                    seated = true;
                    rooms[j] = meetings[i];
                    counter[j]++;
                    cout << "Seating in empty No." << j << ": " << rooms[j][0] << " - " << rooms[j][1] << endl;
                    // lowest time
                    if (minTime > rooms[j][1])
                        minTime = rooms[j][1];
                    break;
                }
                else if (minTime > rooms[j][1])
                        minTime = rooms[j][1];
            }

            if (!seated)
                break;
            runTimeMinTime = minTime;
            minTime = 100000;
            initialIndex++;
        }
        for (int i = 0; i < n; i++)
            if (minTime > rooms[i][1])
                minTime = rooms[i][1];
        

        for (int j = initialIndex; j < meetings.size(); j++)
        {
            auto meet = meetings[j];
            cout << "NEXT " << meet[0] << " - " << meet[1] << " min time to be seated: " << minTime << endl;
            cout << rooms << endl;

            seated = false;
            if (meet[0] + delay <= minTime)
            {
                // add delay so that u will wait till you be seated
                delay = minTime - meet[0];

                cout << "min time change before " << minTime << " delay before " << delay << endl;
            }
            runTimeMinTime = minTime;
            minTime = 100000;
            for (int i = 0; i < n; i++)
            {
                if (rooms[i][1] == runTimeMinTime && !seated)
                {
                    cout << "Seating in No." << i << ": " << meet[0] << " - " << meet[1] << " > previous " << rooms[i][0] << " - " << rooms[i][1] << " delayed " << delay << endl;
                    seated = true;
                    counter[i]++;
                    // seat that person
                    rooms[i] = meet;
                    rooms[i][0] += delay;
                    rooms[i][1] += delay;
                }
                if (rooms[i][1] < minTime)
                {
                    minTime = rooms[i][1];
                }
            }
            if (meet[1] + delay < minTime)
            {
                minTime = meet[1] + delay;
            }
        }
        int max = 0;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "Max " << max << " versus " << counter[i] << " @" << i << endl;
            if (counter[i] > max)
            {
                max = counter[i];
                index = i;
            }
        }
        return index;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> test = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    cout << sol.mostBooked(3, test) << endl;
}