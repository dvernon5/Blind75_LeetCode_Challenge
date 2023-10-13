/*Problem Statement:
  Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
  
  Example 1:
  Input: nums = [1,2,3,1]
  Output: true
  
  Example 2:
  Input: nums = [1,2,3,4]
  Output: false
  
  Example 3:
  Input: nums = [1,1,1,3,3,4,3,2,4,2]
  Output: true
  
  Constraints:
  1 <= nums.length <= 105
  -109 <= nums[i] <= 109

  LeetCode Link: https://leetcode.com/problems/contains-duplicate/
*/
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> unique_numbers;
    for (auto num : nums) {
      // Check if the current number is already in the unique_numbers set.
      if (unique_numbers.count(num) > 0) {
        // If the number is already in the set, It's a duplicate, so return true.
        return true;
      }
      // If the number is not in the set, add it to the set to keep track of unique numbers
      unique_numbers.insert(num);
    }

    // If the loop completes without finding any duplicates, return false.
    return false;
}
