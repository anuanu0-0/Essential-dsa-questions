#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Remove all adjacent duplicates in a given string.
 * Logic : For every character on the string, if the last character is same
 *         then remove the last character else add to result
 * @param s String on which action is to be performed
 * @return string Unique string fullfilling the condition
 */
string removeDuplicates(string s) {

    string result = "";

    for (char ch : s) {
        if (!result.empty() && result[result.size() - 1] == ch)
            result.pop_back();
        else
            result += ch;
    }

    return result;
}
