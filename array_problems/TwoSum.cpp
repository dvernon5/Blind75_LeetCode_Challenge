/*Problem statement:
  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
  
  You may assume that each input would have exactly one solution, and you may not use the same element twice.
  
  You can return the answer in any order.
  
  Example 1:
  Input: nums = [2,7,11,15], target = 9
  Output: [0,1]
  Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
  
  Example 2:
  Input: nums = [3,2,4], target = 6
  Output: [1,2]
  Example 3:
  
  Input: nums = [3,3], target = 6
  Output: [0,1]
   
  Constraints:
  2 <= nums.length <= 104
  -109 <= nums[i] <= 109
  -109 <= target <= 109
  Only one valid answer exists.  

  Leetcode Link: https://leetcode.com/problems/two-sum/
*/
class Solution {
  vector<int> twoSum(vector<int> nums, int target) {
    unordered_map<int, int> number_to_index_map // A map to store numbers and their indices.
    vector<int> result;
    size_t nums_size = nums.size();
    for (size_t current_index = 0; current_index < nums_size; ++current_index) {
      int complement = target - nums[current_index]; // Calculate the complement required to reach the target.
      
      // Check if complement exists, we found a pair that adds up to the target.
      if (number_to_index_map.find(complement) != number_to_index_map.end()) {
        result.push_back(number_to_index_map[complement]);
        result.push_back(current_index);
        return result;  // Return the result immediately since we found a valid pair.
      }
      
      // complement does not exist. Store the current number and its index in the map.
      number_to_index_map[current_index] = current_index;
    }

    return result;  // Return an empty result if no valid pair is found.
  }
};
