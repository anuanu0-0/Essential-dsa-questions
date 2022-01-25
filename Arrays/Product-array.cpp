#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given an integer array nums, return an array answer such that answer[i]
 *        is equal to the product of all the elements of nums except nums[i].
 *        The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 *  Logic :  Use prefix sum technique twice from left to right and right to left
 *           multiplying all the previous numbers into this current position and similarly do  
 *           this while iterating right to left to get desired result.
 * @param nums 
 * @return vector<int> 
 */
vector<int> productExceptSelf(vector<int> &nums) {
    
    vector<int> result(nums.size());
    
    // Left to right
    int prefixMul = 1;
    for (int i = 0; i < nums.size(); i++) {
        result[i] = prefixMul;
        prefixMul *= nums[i];
    }

    // Right to left
    prefixMul = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        result[i] *= prefixMul;
        prefixMul *= nums[i];
    }

    return result;
}