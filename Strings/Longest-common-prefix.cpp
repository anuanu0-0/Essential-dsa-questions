#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Write a function to find the longest common prefix string amongst an array 
 *        of strings.If there is no common prefix, return an empty string "".
 * 
 * Logic : For every string do a vertical scan i.e check i'th character of every string until a mismatch is found
 * @param strs Vector of strings where a common prefix is to be found.
 * @return ** string Longest common prefix
 */
string longestCommonPrefix(vector<string> &strs) {

    int minLen = INT_MAX;
    for (string s : strs)
        minLen = min(minLen, (int)s.size());

    string commonPrefix = "";
    for (int i = 0; i < minLen; i++) {
        char ch = ' ';
        for (string s : strs) {
            if (ch != ' ' ) {
                if (s[i] != ch)
                    return commonPrefix;
            }
            else ch = s[i];
        }

        commonPrefix += ch;
    }

    return commonPrefix;
}