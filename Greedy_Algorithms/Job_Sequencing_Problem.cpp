#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Job Sequencing Problem
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();

        // Store jobs as (profit, deadline)
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Sort jobs by profit in descending order
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

        // Find maximum deadline
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        // Slot array to track occupied time slots
        vector<int> slot(maxDeadline + 1, -1);

        int jobCount = 0;
        int totalProfit = 0;

        // Schedule jobs
        for (int i = 0; i < n; i++) {
            int jobProfit = jobs[i].first;
            int jobDeadline = jobs[i].second;

            // Find a free slot from deadline backwards
            for (int t = jobDeadline; t > 0; t--) {
                if (slot[t] == -1) {
                    slot[t] = jobProfit;
                    jobCount++;
                    totalProfit += jobProfit;
                    break;
                }
            }
        }

        return {jobCount, totalProfit};
    }
};
