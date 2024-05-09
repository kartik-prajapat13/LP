#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Scheduling(vector<int>& profit, vector<int>& deadline)
{
    int n = profit.size();
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; ++i)
    {
        jobs.push_back({profit[i], deadline[i]});
    }

    sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

    int cost = 0;
    int jobCount = 0;
    vector<int> jobSchedule(n, -1);

    for (int i = 0; i < n; ++i)
    {
        int j = jobs[i].second;
        if (j > 0 && jobSchedule[j - 1] == -1)
        {
            jobSchedule[j - 1] = i;
            cost += jobs[i].first;
            jobCount += 1;
        }
        else
        {
            for (int k = j - 1; k >= 0; k--)
            {
                if (jobSchedule[k] == -1)
                {
                    jobSchedule[k] = i;
                    cost += jobs[i].first;
                    jobCount += 1;
                    break;
                }
            }
        }
    }

    cout << "Maximum Profit: " << cost << endl;
    cout << "Jobs Selected: ";
    for (int i = 0; i < jobCount; i++)
    {
        cout << "J" << jobSchedule[i] + 1 << "->";
    }
}

int main()
{
    vector<int> profit = {50, 15, 10, 25};
    vector<int> deadline = {2, 1, 2, 1}; // Corrected variable name

    Scheduling(profit, deadline); // Corrected variable name

    return 0;
}




// profit = {50, 15, 10, 25}
// deadline = {2, 1, 2, 1}

// Maximum Profit: 85
// Jobs Selected: J1->J4->J2->
