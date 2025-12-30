#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// LeetCode 350 - Intersection of Two Arrays II
// Time Complexity: O(n + m)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        vector<int> ans;

        // Count frequency of elements in nums1
        for (int x : nums1) {
            mpp[x]++;
        }

        // Check elements from nums2
        for (int x : nums2) {
            if (mpp[x] > 0) {
                ans.push_back(x);
                mpp[x]--;
            }
        }

        return ans;
    }
};
