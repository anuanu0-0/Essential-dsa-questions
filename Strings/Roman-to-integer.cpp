#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Convert given string in Roman to its integer equivalent
 * 
 * @param s Roman string
 * @return int Integer equivalent of given string
 */
int romanToInt(string s) {
    unordered_map<char, int> m;

    m.insert({'I', 1});
    m.insert({'V', 5});
    m.insert({'X', 10});
    m.insert({'L', 50});
    m.insert({'C', 100});
    m.insert({'D', 500});
    m.insert({'M', 1000});

    int intEquivalent = 0, temp = 0;
    for (int i = 0; i < s.size(); i++) {

        if (i != s.size() - 1 && m[s[i]] < m[s[i + 1]]) {
            temp = m[s[i + 1]] - m[s[i]];
            i++;
        }
        else {
            temp = m[s[i]];
        }

        intEquivalent += temp;
    }

    return intEquivalent;
}