#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Find element at kth position in combined final sorted array.
 *  Concept : Binary search.
 * @param arr1 1st sorted container
 * @param arr2 2nd sorted container
 * @param n Size of first array
 * @param m Size of second array
 * @param k Position of element to be found
 * @return ** int Element at kth position.
 */
int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    // Make sure smaller array is first array
    if (n > m) {
        return kthElement(arr2, arr1, m, n, k);
    }

    int low = max(0, k - m), high = min(k, n);

    int mid1, mid2, l1, l2, r1, r2;
    while (low <= high) {
        mid1 = (low + high) >> 1;
        mid2 = k - mid1;

        // Edge cases
        l1 = mid1 == 0 ? INT_MIN : arr1[mid1 - 1];
        l2 = mid2 == 0 ? INT_MIN : arr2[mid2 - 1];
        r1 = mid1 == n ? INT_MAX : arr1[mid1];
        r2 = mid2 == m ? INT_MAX : arr2[mid2];

        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }

    return -1;
}