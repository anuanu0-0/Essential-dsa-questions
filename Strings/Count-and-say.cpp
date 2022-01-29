#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given an integer n. Return the nth row of the following look-and-say pattern.
    1
    11
    21
    1211
    111221
 * 
 * @param n Number for which pattern is to returned.
 * @return string Pattern following the given conditions.
 */
string countAndSay(int n) {
    string res = "1";

    if (n == 1)
        return res;
    for (int i = 2; i <= n; i++) {
        string temp = "";
        int count = 1;
        int len = res.size();
        char ch = res[0];
        for (int j = 1; j < len; j++) {
            if (ch == res[j])
                count++;
            else {
                temp.append(to_string(count));
                temp.push_back(ch);
                ch = res[j];
                count = 1;
            }
        }

        temp.append(to_string(count));
        temp.push_back(ch);

        res = temp;
    }

    return res;
}