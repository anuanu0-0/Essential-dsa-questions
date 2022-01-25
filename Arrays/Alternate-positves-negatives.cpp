#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given an unsorted array Arr of N positive and negative numbers. 
 *        Your task is to create an array of alternate positive and negative
 *        numbers without changing the relative order of positive and negative numbers.
 * 
 * Logic : Store positives and negatives in individual arrays and copy it back in the sequence asked.
 * @param arr Container consisting of positive and negative values, where changes are to be made.
 * @param n Size of the container.
 */
void rearrange(int arr[], int n) {
    vector<int> positives, negatives;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            negatives.push_back(arr[i]);
        else
            positives.push_back(arr[i]);
    }

    int pSize = positives.size(), nSize = negatives.size();
    for (int i = 0, j = 0; i < n;) {
        if (j < pSize)
            arr[i++] = positives[j];
        if (j < nSize)
            arr[i++] = negatives[j];
        j++;
    }
}