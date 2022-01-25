#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array nums of size n, return the majority element. 
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * Logic : Boyer–Moore majority vote algorithm
 * @param nums 
 * @return int 
 */
int majorityElement(vector<int> &nums) {
    int count = 1, result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == result) count++;
        else count--;

        if (count <= 0) {
            count = 1;
            result = nums[i];
        }
    }

    // Check if the result is a majority element or not
    // Useful in cases when there exists no majority element in provided container
    count = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == result)
            count++;

    if (count >= nums.size() / 2)
        return result;
    else
        return -1;
}