#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an integer array nums of length n and an integer target, 
 *   find three integers in nums such that the sum is closest to target.
 * 
 * Logic : Fix 1 value and run 2 pointer approach for rest of the array.
 *         Check absolute difference and store the sum of closest to target and return.
 * @param nums Container with values where sum is to be found. 
 * @param target Value closest to which sum is to be found.
 * @return int Return the sum of the three integers closest to target.
 */
int threeSumClosest(vector<int> &nums, int target) {

    int n = nums.size();
    sort(nums.begin(), nums.end());

    int absDiff = INT_MAX, sum = 0, bestResult = 0;
    for (int i = 0; i < n; i++) {
        int start = i + 1, end = n - 1;
        while (start < end) {
            sum = nums[i] + nums[start] + nums[end];
            if (sum == target)
                return sum;
            else if (abs(sum - target) < absDiff) {
                absDiff = abs(sum - target);
                bestResult = sum;
            }

            if (sum > target)
                end--;
            else
                start++;
        }
    }

    return bestResult;
}