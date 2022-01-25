#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array of size N, find the smallest positive integer
 *  value that cannot be represented as sum of some elements from the array.
 *  Logic : Sort the array, intialize a variable as 1 as it the min possible candidate for our answer
 *          For each element check if it is greater than our possible answer, if so return
 *          else update our possible answer with the current element
 * @param array Container with values to be searched for
 * @param n size of the container
 * @return ** long long Smallest +ve integer satisfying the above condition
 */
long long smallestpositive(vector<long long> array, int n) {
    sort(array.begin(), array.end());
    long long result = 1;
    for (int i = 0; i < n; i++) {
        if (array[i] > result)
            return result;

        result += array[i];
    }

    return result;
}