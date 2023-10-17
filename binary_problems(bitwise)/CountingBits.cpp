/*Problem Statement
  Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
  Example 1:
  Input: n = 2
  Output: [0,1,1]
  Explanation:
  0 --> 0
  1 --> 1
  2 --> 10
  
  Example 2:
  Input: n = 5
  Output: [0,1,1,2,1,2]
  Explanation:
  0 --> 0
  1 --> 1
  2 --> 10
  3 --> 11
  4 --> 100
  5 --> 101
   
  Constraints:
  0 <= n <= 105
   
  Follow up:
  
  It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
  Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

  LeetCode Link: https://leetcode.com/problems/counting-bits/description/
*/
class Solution {
public:
  vector<int> countBits(int n) {
    // Initialize an array to store the number of 1's for each number from 0 to n + 1.
    vector<int> ans(n +1); 
    for (size_t current_index = 1; current_index <= n; ++current_index) {
      // To find the number of 1's in the binary respresentation of i: 
      // 1. Right-shift i by 1 position (equivalent to dividing by 2) and get the count from ans.
      // 2. Add 1 if the least significant bit (i & 1) is 1, else add 0.
      ans[current_index] = ans[current_index >> 1] + (current_index & 1);
    }
      
    return ans;
  }
};
