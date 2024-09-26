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
    int max_product = nums[0];
    int min_product = nums[0];
    int result = nums[0];
    int length = nums.size();
    for (int i = 1; i < length; i++) {
      int current_max = max_product;
      max_product = max({ nums[i], nums[i] * max_product, nums[i] * min_product });
      min_product = min({ nums[i], nums[i] * current_max, nums[i] * min_product });
      result = max(result ,max_product);
    }

    return result;
  }
};
