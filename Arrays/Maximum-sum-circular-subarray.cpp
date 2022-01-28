#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given a circular integer array nums of length n, 
 * return the maximum possible sum of a non-empty subarray of nums
 * Logic :  Use kadane's algorithm for maxSubarraySum and minSubarraySum.
 *          Performing difference of total sum - minSubarraySum will give sum of circular elements.
 * @param nums Container with values for finding circular subarray sum
 * @return ** int Maximum subarray sum including circular subarray sum.
 */

/******* METHOD 1 ********/
// Kadane's algorithm acting as subroutine
int maxSubarraySum(vector<int> nums) {

    int maxEnding = nums[0], result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        maxEnding = max(maxEnding + nums[i], nums[i]);
        result = max(result, maxEnding);
    }

    return result;
}

int maxSubarraySumCircular(vector<int> &nums) {

    int normalSubarraySum = maxSubarraySum(nums);

    int totalSum = 0, countNegative = 0;
    for (int i = 0; i < nums.size(); i++) {
        totalSum += nums[i];
        if (nums[i] < 0) countNegative++;
        nums[i] *= -1;
    }

    int circularSubarraySum = totalSum + maxSubarraySum(nums);
    if (countNegative == nums.size())
        return normalSubarraySum;
    else
        return max(normalSubarraySum, circularSubarraySum);
}


/******* METHOD 2 ********/
int maxSubarraySumCircular(vector<int> &nums) {
    int totalSum = 0;
    int curMax = 0, maxRes = INT_MIN;
    int curMin = 0, minRes = INT_MAX;

    for (int num : nums) {

        totalSum += num;
        curMax = max(curMax + num, num);
        maxRes = max(maxRes, curMax);

        curMin = min(curMin + num, num);
        minRes = min(minRes, curMin);
    }

    if (maxRes < 0)
        return maxRes;
    return max(maxRes, totalSum - minRes);
}