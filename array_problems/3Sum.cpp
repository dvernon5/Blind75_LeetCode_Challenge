/*Problem Statement:
  Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
  
  Notice that the solution set must not contain duplicate triplets.
  
  Example 1:
  Input: nums = [-1,0,1,2,-1,-4]
  Output: [[-1,-1,2],[-1,0,1]]
  Explanation: 
  nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
  nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
  nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
  The distinct triplets are [-1,0,1] and [-1,-1,2].
  Notice that the order of the output and the order of the triplets does not matter.
  
  Example 2:
  Input: nums = [0,1,1]
  Output: []
  Explanation: The only possible triplet does not sum up to 0.
  
  Example 3:
  Input: nums = [0,0,0]
  Output: [[0,0,0]]
  Explanation: The only possible triplet sums up to 0.
   
  
  Constraints:
  3 <= nums.length <= 3000
  -105 <= nums[i] <= 105
  
  LeetCode Link: https://leetcode.com/problems/3sum/
*/
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    size_t nums_size = nums.size(); // Store the size of the input array to avoid recomputation.
    for (size_t current_index = 0; current_index < nums_size - 2; ++current_index) {
      // Skip duplicates to avoid duplicate triplets
      if (current_index == 0 || nums[current_index] != nums[current_index - 1]) {
        size_t left = current_index + 1;
        size_t right = nums.size() - 1;
        while (left < right) {
          auto target = -1 * nums[current_index];
          auto sum = nums[left] + nums[right];
          if (sum == target) {
            // Found a valid triplet, add it to the result.
            result.push_back({ nums[current_index], nums[left], nums[right] });

            // Skip duplicate values
            while (left < right && nums[left] == nums[left + 1]) {
              ++left;
            }
            while (left < right && nums[right] == nums[right - 1]) {
              --right;
            }
            ++left;
            --right;
          } else if (sum < target) {
            ++left;
          } else {
            --right;
          }
        }
      }
    }

    return result;
  }
};
