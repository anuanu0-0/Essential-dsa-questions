#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array, rotate the array to the right by k steps, where k is non-negative.
 *  Logic : Reverse 0-k-1, k-n elements in a group. Again reverse 0-n elements.
 *  n is the size of the container
 * @param nums Container with values to be rotated.
 * @param k Number of steps to be rotated
 */
void rotate(vector<int> &nums, int k) {
    auto start = nums.begin(), end = nums.end();
    int n = nums.size();
    k = k % n;
    reverse(start, start + n - k);
    reverse(start + n - k, end);
    reverse(start, end);
}