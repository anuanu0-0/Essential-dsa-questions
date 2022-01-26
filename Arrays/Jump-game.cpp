#include <bits/stdc++.h>
using namespace std;

/**
 * @brief You are given an integer array nums. You are initially positioned at the array's
 *        first index, and each element in the array represents your maximum jump length at that position.
 *        Return true if you can reach the last index, or false otherwise.
 * 
 * Logic : For any index mark the maximum we can go forward in a variable and update the variable for
 *         higher reachable indexes. If after traversal we reach last index return true else false.
 * @param nums Container with values to be checked for. 
 * @return true Last index is reachable.
 * @return false Last index is not reachable.
 */
bool canJump(vector<int> &nums) {
    int lastReachableIndex = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (i + nums[i] >= lastReachableIndex)
            lastReachableIndex = i;
    }

    return lastReachableIndex == 0;
}