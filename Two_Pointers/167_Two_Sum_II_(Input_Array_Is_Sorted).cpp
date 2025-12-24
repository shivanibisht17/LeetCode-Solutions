#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// LeetCode 167 - Two Sum II (Input Array Is Sorted)
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1}; // 1-based indexing
            }
            else if (sum > target) {
                right--;
            }
            else {
                left++;
            }
        }
        return {};
    }
};
