#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Implement the myAtoi(string s) function, which converts a string 
 *        to a 32-bit signed integer (similar to C/C++'s atoi function).
 * 
 * @param s String to be converted into integer
 * @return ** int Integer equivalent of the string provided
 */
int myAtoi(string s) {

    long int digit = 0;

    int idx = 0;
    while (idx < s.size() && s[idx] == ' ')
        s.erase(s.begin());

    int sign = s[idx] == '-' ? -1 : 1;

    while(idx < s.size()) {
        if (s[0] == '+' || s[0] == '-')
            s.erase(s.begin());
        if (s[idx] >= 48 && s[idx] <= 57 && digit <= INT_MAX) {
            digit = digit * 10 + (s[idx++] - '0');
        }
        else break;
    }

    digit = (sign == -1) ? -digit : digit;
    
    if (digit >= INT_MAX)
        return INT_MAX;
    else if (digit <= INT_MIN)
        return INT_MIN;

    return (int)digit;
}