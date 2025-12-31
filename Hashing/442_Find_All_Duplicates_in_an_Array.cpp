#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// LeetCode 442 - Find All Duplicates in an Array
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> ans;

        // Count frequency of elements
        for (int x : nums) {
            mpp[x]++;
        }

        // Collect elements with frequency > 1
        for (auto it : mpp) {
            if (it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
