/* 322. Coin Change Problem Statement.
 You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
 
 Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 
 You may assume that you have an infinite number of each kind of coin.
 
 Example 1:
 Input: coins = [1,2,5], amount = 11
 Output: 3
 Explanation: 11 = 5 + 5 + 1
 
 Example 2:
 Input: coins = [2], amount = 3
 Output: -1
 
 Example 3
 Input: coins = [1], amount = 0
 Output: 0

 Constraints:
 1 <= coins.length <= 12
 1 <= coins[i] <= 231 - 1
 0 <= amount <= 104
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount + 1, -2);
        
        return coinChangeHelper(coins, amount);
    }

private:
    vector<int> memo;
    int coinChangeHelper(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (memo[amount] != -2) return memo[amount];
        int minCoin = INT_MAX;
        for (const auto& coin : coins) {
            int result = coinChangeHelper(coins, amount - coin);
            if (result >= 0 && result < minCoin) {
                minCoin = result + 1;
            }
        }
        memo[amount] = (minCoin == INT_MAX) ? -1 : minCoin;
        
        return memo[amount];
    }
};
