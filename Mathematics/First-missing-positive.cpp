#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an unsorted integer array nums, return the smallest missing positive integer.
 * Logic : Place all the numbers between 0 and container size to their correct positions w.r.t 0 based indexing
 *         Reiterate the array and compare indexes to find if missing element is in [0-size] else return size + 1 
 * @param nums Container values to be searched.
 * @return int smallest missing positive integer
 */
int firstMissingPositive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] < 0 ? -1 : nums[i];
        int correctPos = nums[i] - 1;
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[correctPos]) {
            swap(nums[i], nums[correctPos]);
            correctPos = nums[i] - 1;
        }
    }

    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != i + 1)
            return i + 1;

    return nums.size() + 1;
}