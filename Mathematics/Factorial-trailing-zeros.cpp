#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given an integer n, return the number
 *  of trailing zeroes in n!.
 * Logic : Count the number of power of 5's as they make 10's.
 * @param n The number whose trailing zeros have to be found.
 * @return int Number of trailing zeros in the factorial 
 */
int trailingZeroes(int n) {
    int powerOfFive = 5, result = 0;
    while (powerOfFive <= n) {
        result += n / powerOfFive;
        powerOfFive *= 5;
    }

    return result;
}