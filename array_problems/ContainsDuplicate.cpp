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
    bool is_duplicate = false;
    for (auto num : nums) {
      if (unique_numbers.count(num) > 0) {
        return true;
      }
      unique_numbers.insert(num);
    }
    
    return false;
}


// Alternative Solution:
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> unique_numbers;
    for (auto num : nums) {
      if (unique_numbers.find(num) != unique_numbers.end()) {
        return true;
      }
      unique_numbers.insert(num);
    }
    
    return false;
}
