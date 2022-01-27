#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an integer array nums, return the maximum difference between two successive
 *        elements in its sorted form. If the array contains less than two elements, return 0.
 *        You must write an algorithm that runs in linear time and uses linear extra space.
 *  Concept : Bucket sort, pigeonhole principle
 * @param nums Container with elements for which max gap is to be found.
 * @return ** int Return max gap between successive elements if container was sorted.
 */
int maximumGap(vector<int> &nums)
{
    if (nums.size() < 2)
        return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;

    for (int num : nums)
    {
        minVal = min(minVal, num);
        maxVal = max(maxVal, num);
    }

    // Giving overflow error for this bucket size declaration
    // int bucketSize = ceil((maxVal - minVal) / (nums.size()-1));
    int bucketSize = (int)ceil((double)(maxVal - minVal) / (nums.size() - 1));

    // Store min and max of each bucket
    vector<int> minBucket(nums.size() - 1, INT_MAX), maxBucket(nums.size() - 1, INT_MIN);
    int bucketIndex;

    // Store min value and max value of each bucket in respective buckets
    // based on the bucket index. Ignore minVal and maxVal calculated above.
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == minVal || nums[i] == maxVal)
            continue;

        // Calculate the bucket index to put the element
        bucketIndex = (nums[i] - minVal) / bucketSize;

        minBucket[bucketIndex] = min(minBucket[bucketIndex], nums[i]);
        maxBucket[bucketIndex] = max(maxBucket[bucketIndex], nums[i]);
    }

    // Calculate the maximum gap by taking the difference of min value
    // of current bucket and max value of previous non empty bucket
    int maxGap = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        // Ignore an empty bucket
        if (maxBucket[i] == INT_MIN)
            continue;
        maxGap = max(maxGap, minBucket[i] - minVal);
        minVal = maxBucket[i];
    }

    return max(maxGap, maxVal - minVal);
}