#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given n non-negative integers representing an elevation map where the width of 
 *        each bar is 1, compute how much water it can trap after raining.
 *  Logic : Compute and store left max height and right max height for each element.
 *          Then water stored can be calculated as difference of minimum of left, right boundary 
 *          and current height
 * @param height Container with heights of the bars in the elevation map
 * @return ** int Maximum water trapped. 
 */
int trap(vector<int> &height) {

    int n = height.size();
    vector<int> leftBoundary(n), rightBoundary(n);

    // Store left max height and right max height for every element
    leftBoundary[0] = height[0];
    for (int i = 1; i < n; i++)
        leftBoundary[i] = max(leftBoundary[i - 1], height[i]);

    rightBoundary[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightBoundary[i] = max(rightBoundary[i + 1], height[i]);

    int waterTrapped = 0, minHeight = 0;
    for (int i = 1; i < n - 1; i++) {
        minHeight = min(leftBoundary[i], rightBoundary[i]);
        if (minHeight > height[i])
            waterTrapped += minHeight - height[i];
    }

    return waterTrapped;
}