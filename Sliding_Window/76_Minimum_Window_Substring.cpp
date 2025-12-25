#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// LeetCode 76 - Minimum Window Substring
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);

        for (char c : t) {
            freq[c]++;
        }

        int left = 0, right = 0;
        int count = 0;
        int minLen = INT_MAX;
        int startIndex = -1;

        while (right < s.size()) {
            if (freq[s[right]] > 0) {
                count++;
            }
            freq[s[right]]--;

            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    count--;
                }
                left++;
            }

            right++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};
