#include <bits/stdc++.h>
using namespace std;

/**
 * @brief We are given an array prices where prices[i] is the price of a given stock on the ith day.
 *        You want to maximize your profit by choosing a single day to buy one stock and choosing a 
 *        different day in the future to sell that stock.
 *  Logic : Sort of Kadane's algorithm
 * @param prices Container with stock prices to calculate maximum profit 
 * @return int Return the maximum profit you can achieve from this transaction. If not, return 0.
 */
int maxProfit(vector<int> &prices) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int profit{}, minPrice{prices[0]};

    for (auto &&curPrice : prices) {
        profit = max(profit, curPrice - minPrice);
        minPrice = min(minPrice, curPrice);
    }

    return profit > 0 ? profit : 0;
}