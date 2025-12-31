#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// LeetCode 974 - Subarray Sums Divisible by K
// Time Complexity: O(n)
// Space Complexity: O(k)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefixSum = 0;
        int cnt = 0;

        for (int x : nums) {
            prefixSum += x;
            int rem = prefixSum % k;

            if (rem < 0) rem += k;

            if (mp.count(rem)) {
                cnt += mp[rem];
            }

            mp[rem]++;
        }
        return cnt;
    }
};
