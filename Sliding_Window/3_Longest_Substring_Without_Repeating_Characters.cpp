#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// LeetCode 3 - Longest Substring Without Repeating Characters
// Approach: Sliding Window | Time: O(n) | Space: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int l = 0;
        vector<int> freq(256, 0);

        for(int r = 0; r < s.length(); r++) {
            freq[s[r]]++;

            while(freq[s[r]] > 1) {
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
