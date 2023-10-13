/*Problem Statement:
  Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

  The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
  
  You must write an algorithm that runs in O(n) time and without using the division operation.
  
  Example 1:
  Input: nums = [1,2,3,4]
  Output: [24,12,8,6]
  
  Example 2:
  Input: nums = [-1,1,0,-3,3]
  Output: [0,0,9,0,0]
   
  Constraints:
  2 <= nums.length <= 105
  -30 <= nums[i] <= 30
  The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

  Leetcode Link: https://leetcode.com/problems/product-of-array-except-self/
*/
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    size_t nums_size = nums.size();
    vector<int> prefix_product(nums_size); // An array to store the product of prefixes.
    prefix_product[0] = 1;
    
    // Calculate the product of prefixes.
    for (size_t current_index = 1; current_index < nums_size; ++current_index) {
      prefix_product[current_index] = prefix_product[current_index - 1] * nums[current_index - 1];
    }
    vector<int> suffix_product(nums_size); // An array to store the product of suffixes.
    suffix_product[nums_size - 1] = 1;
    
    // Calculate the product of suffixes. 
    for (size_t current_index = nums_size - 2; current_index >= 0; --current_index) {
      suffix_product[current_index] = suffix_product[current_index + 1] * nums[current_index + 1];
    }

    // Calculate the result array by multiplying the corresponding prefix and suffix products. 
    vector<int> result_array(nums_size);
    for (size_t current_index = 0; current_index < nums_size; ++current_index) {
      result_array[current_index] = prefix_product[current_index] * suffix_product[current_index];
    }

    return result_array;
  }
};
