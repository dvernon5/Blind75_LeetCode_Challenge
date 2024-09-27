/* 300. Longest Increasing Subsequence Problem Statement
 Given an integer array nums, return the length of the longest strictly increasing subsequence.

 Example 1:
 Input: nums = [10,9,2,5,3,7,101,18]
 Output: 4
 Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 
Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
 
Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 
Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> memo(nums.size(), 1);
      int length = nums.size() - 1;
      for (int i = length; i >= 0; i--) {
        for (int j = i + 1; j <= length; j++) {
          if (nums[i] < nums[j]) {
            memo[i] = max(memo[i], 1 + memo[j]);
          }
        }
      }

      return *max_element(memo.begin(), memo.end());
    }
};
