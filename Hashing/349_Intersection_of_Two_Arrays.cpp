#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// LeetCode 349 - Intersection of Two Arrays
// Time Complexity: O(n + m)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;

        for (int x : nums2) {
            if (s.count(x)) {
                ans.push_back(x);
                s.erase(x); // to avoid duplicates in result
            }
        }

        return ans;
    }
};
