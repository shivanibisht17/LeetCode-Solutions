#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// LeetCode 1975 - Maximum Matrix Sum
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        int n = matrix.size();

        // Traverse the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];

                if (val < 0) {
                    negCount++;
                }

                sum += abs(val);
                minAbs = min(minAbs, abs(val));
            }
        }

        // If number of negatives is odd, subtract twice the smallest absolute value
        if (negCount % 2 == 1) {
            sum -= 2LL * minAbs;
        }

        return sum;
    }
};
