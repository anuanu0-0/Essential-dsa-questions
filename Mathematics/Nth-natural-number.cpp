#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given a positive integer N, we have to find Nth natural 
 * number after removing all the numbers containing digit 9.
 * Logic : Convert the given number from base10 to base9 (0-8),  
 *         doing this makes sure that proper mapping takes place.
 *         Eg : 8 maps to 8, 9 maps to 10, and so on.. 
 * @param N The required position of number to be returned after doing the operation.
 * @return ** long long Nth natural number after removing all numbers with digit 9
 */
long long findNth(long long N) {
    long long pos = 1;
    long long base = 9;
    long long result = 0;
    while (N > 0) {
        result += (N % base) * pos;
        N = N / base;
        pos *= 10;
    }

    return result;
}