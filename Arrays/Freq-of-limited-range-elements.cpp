#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array A[] of N positive integers which can contain integers 
 *        from 1 to P where elements can be repeated or can be absent from the array. 
 *        Your task is to count the frequency of all elements from 1 to N.
 *  Logic : For every i, add a unique prime number(>size of array) to the i'th index arr[i]
 *          for every i found in the given array.
 * @param arr Container with positive values from 1 to P
 * @param n Size of the container
 * @param P Upper limit of elements found in array arr.
 */
void frequencyCount(vector<int> &arr, int n, int P) {

    // Choosing a prime number as hash key
    // where n is always less than hashKey
    const int hashKey = 100007;
    for (int i = 0; i < n; i++) {
        int correctPos = arr[i] - 1;
        if (correctPos % hashKey < n)
            arr[correctPos % hashKey] += hashKey;
    }

    for (int i = 0; i < n; i++){
        arr[i] = (arr[i] - arr[i] % hashKey) / hashKey;
    }
}