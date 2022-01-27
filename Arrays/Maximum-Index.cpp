#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array A[] of N positive integers. The task is to find the maximum 
 *        of j - i subjected to the constraint of A[i] < A[j] and i < j.
 *  Logic : Create 2 arrays and store left minimum and right maximum for every element in respective arrays.
 *          Iterate for right max array. For every element check if it greater than leftMin i'th index, 
 *          if so continue incrementing right max array index and store the index diff. If not increment left min array index. 
 * @param A Container with values where max index is to be found
 * @param N Size of the container
 * @return ** int Max index following the given conditions.
 */
int maxIndexDiff(int A[], int N) {
    int leftMin[N], rightMax[N];

    leftMin[0] = A[0];
    for (int i = 1; i < N; i++)
        leftMin[i] = min(leftMin[i - 1], A[i]);

    rightMax[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], A[i]);

    int maxIndex = INT_MIN;
    for (int i = 0, j = 0; i < N && j < N;) {
        if (rightMax[j] >= leftMin[i]) {
            maxIndex = max(maxIndex, j - i);
            j++;
        } else i++;
    }

    return maxIndex;
}