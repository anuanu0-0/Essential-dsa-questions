#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array arr[] of N positive integers. 
 *        Find maximum value of |arr[i] – arr[j]| + |i – j|, (0 <= i, j <= N – 1)
 * Logic : There are 4 possible cases : ++, --, +-, -+.
 *         In which ++ & -- pairs absolute value produces max result.
 *         arr[i] - arr[j] + i - j  => (arr[i] + i) - (arr[j] + j)
 *        -arr[i] + arr[j] - i + j  => (i - arr[i]) + (j - arr[j])
 * 
 * @param arr Container with values for computation
 * @param n Size of array
 * @return int Maximum result satisfying the given equation 
 */
int maxValue(int arr[], int n) {

    int min1 = INT_MAX, max1 = INT_MIN, min2 = INT_MAX, max2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        min1 = min(min1, arr[i] + i);
        max1 = max(max1, arr[i] + i);
        min2 = min(min2, i - arr[i]);
        max2 = max(max2, i - arr[i]);
    }

    return max(max1 - min1, max2 - min2);
}