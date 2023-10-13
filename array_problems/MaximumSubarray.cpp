/*Problem Statement:
  Given an integer array nums, find the subarray with the largest sum, and return its sum.
  
  Example 1:
  Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
  Output: 6
  Explanation: The subarray [4,-1,2,1] has the largest sum 6.
  
  Example 2:
  Input: nums = [1]
  Output: 1
  Explanation: The subarray [1] has the largest sum 1.
  
  Example 3:
  Input: nums = [5,4,-1,7,8]
  Output: 23
  Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
   
  Constraints:
  1 <= nums.length <= 105
  -104 <= nums[i] <= 104

  LeetCode Link = https://leetcode.com/problems/maximum-subarray/
*/
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int max_sum = INT_MIN; // Largest subarray sum, initialized as a very small value.
    int current_sum = 0;   // Current subarray sum, initialized as 0. 
    size_t nums_size = nums.size();
    for (int current_index = 0; current_index < nums_size; ++current_index) {
      // Adding the current eleemnt to the current subarray sum.
      current_sum += nums[current_index];

      // Check if current subarray sum is greater than the largest seen so far.
      if (current_sum > max_sum) {
        max_sum = current_sum;
      }

      // If the current subarray sum becomes negative, reset it to 0.
      if (current_sum < 0) {
        current_sum = 0;
      }
    }

    return max_sum;
  }
};
