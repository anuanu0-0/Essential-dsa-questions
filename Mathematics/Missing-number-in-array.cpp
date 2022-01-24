#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array nums containing n distinct numbers in the range [0, n],
 *  return the only number in the range that is missing from the array.
 * Logic : Compute sum of n natural numbers and subtract the numbers in the list to get the missing number
 * @param nums distinct list of numbers
 * @return int missing number in the range [0-n]
 */
int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int sum = (n * n+1)/2;
    for (int i = 0; i < n; i++)
        sum -= nums[i];
    return sum;
}