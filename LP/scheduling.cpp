#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Scheduling(vector<int>& profit, vector<int>& deadline)
{
    int n = profit.size();

    // Sorting jobs based on profit in descending order
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (profit[j] > profit[i])
            {
                swap(profit[j], profit[i]);
                swap(deadline[j], deadline[i]);
            }
        }
    }

    // Initializing job schedule, cost, and job count
    vector<int> jobSchedule(n, -1);
    int cost = 0;
    int jobCount = 0;

    for (int i = 0; i < n; i++)
    {
        int j = deadline[i];
        if (j > 0 && jobSchedule[j - 1] == -1)
        {
            jobSchedule[j - 1] = i;
            cost += profit[i];
            jobCount += 1;
        }
        else
        {
            for (int k = j - 1; k >= 0; k--)
            {
                if (jobSchedule[k] == -1)
                {
                    jobSchedule[k] = i;
                    cost += profit[i];
                    jobCount += 1;
                    break;
                }
            }
        }
    }

    // Printing the results
    cout << "Maximum Profit: " << cost << endl;
    cout << "Jobs Selected: ";
    for (int i = 0; i < jobCount; i++)
    {
        cout << "J" << jobSchedule[i] + 1 << "->";
    }
}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<int> profit(n);
    vector<int> deadline(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit of " << i + 1 << "th job: ";
        cin >> profit[i];
        cout << "Enter deadline of " << i + 1 << "th job: ";
        cin >> deadline[i];
    }

    Scheduling(profit, deadline);

    return 0;
}




// Enter number of jobs: 4
// Enter profit of 1th job: 50
// Enter deadline of 1th job: 2
// Enter profit of 2th job: 15
// Enter deadline of 2th job: 1
// Enter profit of 3th job: 10
// Enter deadline of 3th job: 2
// Enter profit of 4th job: 25
// Enter deadline of 4th job: 1
