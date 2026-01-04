#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Activity Selection Problem
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        if (n == 0) return 0;

        vector<pair<int, int>> activities;

        // Store activities as (finish time, start time)
        for (int i = 0; i < n; i++) {
            activities.push_back({finish[i], start[i]});
        }

        // Sort activities by finish time
        sort(activities.begin(), activities.end());

        int count = 1;  // First activity is always selected
        int lastFinish = activities[0].first;

        // Select remaining activities
        for (int i = 1; i < n; i++) {
            if (activities[i].second >= lastFinish) {
                count++;
                lastFinish = activities[i].first;
            }
        }

        return count;
    }
};
