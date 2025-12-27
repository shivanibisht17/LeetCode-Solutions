#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// LeetCode 1 - Two Sum
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if (mpp.find(need) != mpp.end()) {
                return {mpp[need], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};
