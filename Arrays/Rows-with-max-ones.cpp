#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given a boolean 2D array of n x m dimensions where each row is sorted. 
 *  Find the 0-based index of the first row that has the maximum number of 1's.
 * 
 * Logic : Start from top right corner and move down for arr[i][j]=0 and left 
 *         elsewise. When we reach leftmost column or last row our loop breaks
 *         and what is stored in result is returned.
 * @param arr Matrix with 0 and 1 values, sorted row wise. 
 * @param n Row size
 * @param m Column size
 * @return int First row with max ones
 */
int rowWithMax1s(vector<vector<int>> arr, int n, int m) {

    int result = -1;
    for (int i = 0, j = m - 1; i < n && j < m;)
    {
        // If arr[i][j] == 0 => move down
        // If arr[i][j] == 1 => move left;
        if (arr[i][j] == 0) {
            i++;
        }
        else {
            j--;
            result = i;
        }
    }

    return result;
}