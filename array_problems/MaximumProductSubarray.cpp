/*Problem Statement:
  Given an integer array nums, find a subarray that has the largest product, and return the product.

  The test cases are generated so that the answer will fit in a 32-bit integer.
  
  Example 1:
  Input: nums = [2,3,-2,4]
  Output: 6
  Explanation: [2,3] has the largest product 6.
  
  Example 2:
  Input: nums = [-2,0,-1]
  Output: 0
  Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
   
  Constraints:
  1 <= nums.length <= 2 * 104
  -10 <= nums[i] <= 10
  The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

  LeetCode Line: https://leetcode.com/problems/maximum-product-subarray/submissions/
*/
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int max_product = nums[0];  // Keep track of the maximum product.
    int min_product = nums[0];  // Keep track of the minimum product.
    int result = nums[0];
    size_t nums_size = nums.size(); 
    for (int current_index = 1; current_index < nums_size; ++current_index) {
      // Temporary variable to store the current maximum product. 
      int temp_max_product = max_product;

      // Update the maximum product by considering three possibilities:
      // 1. The current number by itself.
      // 2. The current number multiplied by the previous maximum product.
      // 3. The current number multiplied by the previous minimum product. 
      max_product = max({nums[current_index], max_product * nums[current_index], min_product * nums[current_index]});

      // Update the minimum procut in a similar way as the maximum product.
      min_product = min({nums[current_index], temp_max_product * nums[current_index], min_product * nums[current_index]});

      // Update the final result by taking the maximum of the current result and the new maximum product. 
      result = max(result, max_product);
    }

    return result;
  }
};
