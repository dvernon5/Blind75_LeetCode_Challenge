/*Problem Statement:
  There is an integer array nums sorted in ascending order (with distinct values).
  
  Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],   
  nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become 
  [4,5,6,7,0,1,2].
  
  Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
  
  You must write an algorithm with O(log n) runtime complexity.
  
  Example 1:
  Input: nums = [4,5,6,7,0,1,2], target = 0
  Output: 4
  
  Example 2:
  Input: nums = [4,5,6,7,0,1,2], target = 3
  Output: -1
  
  Example 3:
  Input: nums = [1], target = 0
  Output: -1
   
  Constraints:
  1 <= nums.length <= 5000
  -104 <= nums[i] <= 104
  All values of nums are unique.
  nums is an ascending array that is possibly rotated.
  -104 <= target <= 104

  LeetCode Link: https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
*/
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left_index = 0;
    int right_index = nums.size() - 1;
    while (left_index <= right_index) {
      int middle_index = left_index + (right_index - left_index) / 2;
      if (nums[middle_index] == target) {
        return middle_index;
      }
      if (nums[left_index] <= nums[middle_index]) {
        // If the right half is sorted
        if (target > nums[middle_index] || target < nums[left_index]) {
          // If the target is in the right half, update the left pointer.
          left_index = middle_index + 1;
        } else {
          // Otherwise, update the right pointer.
          right_index = middle_index - 1;
        }
      } else {
        // If the left half is sorted
        if (target < nums[middle_index] || target > nums[right_index]) {
          // If the target is in the left half, update the right pointer.
          right_index = middle_index - 1;
        } else {
          // Otherwise, update the left pointer.
          left_index = middle_index + 1;
        }
      }
    }
    
    return -1;
  }
};
