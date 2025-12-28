#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// LeetCode 217 - Contains Duplicate
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            if (mpp.find(nums[i]) != mpp.end()) {
                return true;
            }
            mpp[nums[i]] = i;
        }
        return false;
    }
};
