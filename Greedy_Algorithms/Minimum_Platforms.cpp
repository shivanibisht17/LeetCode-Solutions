#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Minimum Platforms Problem
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    int minPlatform(vector<int> &arr, vector<int> &dep) {
        int n = arr.size();
        if (n == 0) return 0;

        // Sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms = 1;        // Platforms currently needed
        int maxPlatforms = 1;     // Maximum platforms needed
        int i = 1, j = 0;

        // Traverse arrival and departure arrays
        while (i < n && j < n) {
            // If next train arrives before previous departs
            if (arr[i] <= dep[j]) {
                platforms++;
                i++;
            } 
            // If a train departs before next arrival
            else {
                platforms--;
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }

        return maxPlatforms;
    }
};
