#include<bits/stdc++.h>
using namespace std;

/**
 * @brief You are given a large integer represented as an integer array digits,
 *  where each digits[i] is the ith digit of the integer. The digits are ordered 
 *  from most significant to least significant in left-to-right order. The large
 *  integer does not contain any leading 0's.Increment the large integer by one 
 *  and return the resulting array of digits.
 * 
 * Logic : Traverse the array from last element and keep on performing addition 
 *         if carry=1 from last operation. If after complete traversal the carry
 *         is still 1, then insert 1 at the start of the vector.
 * @param digits Container containing number as a list of digits.
 * @return vector<int> Result after adding one to the number(represented as list)
 */
vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
    for(int i=digits.size()-1; i>=0 && carry!=0; --i) {
        if(digits[i]==9) {
            digits[i]=0;
        } else {
            digits[i] = digits[i]+(carry--);
        }
    }
        
    if(carry==1)
        digits.insert(digits.begin(), carry--);
    
    return digits;
}