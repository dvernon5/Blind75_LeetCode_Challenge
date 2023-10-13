/*Problem Statement
 You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 
Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 104

LeetCode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int minimum_price = INT_MAX;  // To keep track of the minimum price seen so far.
    int max_profit = 0;
    size_t prices_size = prices.size();
    for (size_t current_index = 0; current_index < prices_size; ++current_index) {
      // Check if the current price is lower than the minimum price seen so far
      if (prices[i] < minimum_price) {
        // Update the minimum price if a lower price is found.
        minimum_price = prices[i];
      }
      // Check if the profit from selling at the current price is higher than the max profit.
      else if (prices[i] - minimum_price > max_profit) {
        // Update the max profit if a higher profit is achieved.
        max_profit = prices[i] - minimum_price;
      }
    }

    return max_profit;
  }
};
