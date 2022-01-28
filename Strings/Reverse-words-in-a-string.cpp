#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given an input string s, reverse the order of the words. Return a 
 *        string of the words in reverse order concatenated by a single space.
 *  Logic : Do reversal in groups then remove uncessary spaces.
 * @param s String to be reversed.
 * @return string Reversed string w.r.t given conditions.
 */
string reverseWords(string s) {

    // Problem 1 : Reverse words
    reverse(s.begin(), s.end());
    int cur = 0, start = 0;
    for (; cur < s.size(); cur++) {
        if (s[cur] == ' ') {
            reverse(s.begin() + start, s.begin() + cur);
            start = cur + 1;
        }
    }

    reverse(s.begin() + start, s.end());

    // Problem 2 : Remove unnecessary spaces
    // Removing leading and trailing spaces
    int idx = 0;
    while (idx < s.size() && s[idx] == ' ')
        s.erase(s.begin());

    idx = s.size() - 1;
    while (idx >= 0 && s[idx] == ' ')
        s.erase(s.begin() + (idx--));

    // Removing duplicate zeros
    idx = 1;
    while (idx < s.size()) {
        if (s[idx] == ' ' && s[idx + 1] == ' ')
            s.erase(s.begin() + idx);
        else
            idx++;
    }

    return s;
}
