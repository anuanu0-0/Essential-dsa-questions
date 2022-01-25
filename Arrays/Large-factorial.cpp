#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array A of integers of length N. We need to calculate factorial of each number.
 *        The answer can be very large, so print it modulo 109 + 7.
 *  Logic : Precompute factorial array for max range provided and using this as base 
 *          print/return result for every query
 * @param a Container with values whose factorial is to calculated
 * @param n Size of the array
 * @return vector<long long> List of computed factorials
 */
vector<long long> factorial(vector<long long> a, int n) {
    const int MAX = 1e5;
    long long fact[MAX + 1], mod = 1e9 + 7;
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        fact[i] = fact[i - 1] % mod * i % mod;
    }

    vector<long long> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = fact[a[i]];
    }

    return result;
}