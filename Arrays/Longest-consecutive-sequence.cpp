#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an unsorted array of integers nums, return the length of the longest consecutive
 *       elements sequence. You must write an algorithm that runs in O(n) time.
 *  Logic : Use hashing (hashset used here) for keeping a track of sorted unique elements 
 *          and then using greedy approach count the maximum consexutive streak.
 * @param nums Container with values for the computation
 * @return int Count of longest consecutive elements sequence
 */
int longestConsecutive(vector<int> &nums) {
    set<int> numSet;
    for (int i : nums)
        numSet.insert(i);

    // If streak continues increase count
    // When streak breaks update current streak = 1 and update maxStreak to whatever is larger
    int longestConsecutiveCount = 0, currentConsecutiveCount = 0, last = INT_MIN;
    for (int num : numSet) {
        if (last == INT_MIN) {
            last = num;
            currentConsecutiveCount = 1;
        }
        else {
            if (num == last + 1) currentConsecutiveCount++;
            else {
                longestConsecutiveCount = max(longestConsecutiveCount, currentConsecutiveCount);
                currentConsecutiveCount = 1;
            }

            last = num;
        }
    }

    // Edge case when all elements are in streak and this comparison never takes place.
    return max(longestConsecutiveCount, currentConsecutiveCount);
}