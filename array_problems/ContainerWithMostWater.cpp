/*Problem Statements:
  You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
  
  Find two lines that together with the x-axis form a container, such that the container contains the most water.
  
  Return the maximum amount of water a container can store.
  
  Notice that you may not slant the container.
  
  8|    ___                           ___
  7|    _____________________________________________
  6|    | |   ___                     | |         | |
  5|    | |   | |         ___         | |         | |
  4|    | |   | |         | |   ___   | |         | |
  3|    | |   | |         | |   | |   | |   ___   | |
  2|    | |   | |   ___   | |   | |   | |   | |   | |
  1|__  | |   | |   | |   | |   | |   | |   | |   | |
  0|_|__|_|___|_|___|_|___|_|___|_|___|_|___|_|___|_|
    0    1     2     3     4     5     6     7     8 
    
  Example 1:
  Input: height = [1,8,6,2,5,4,8,3,7]
  Output: 49
  Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
  Example 2:
  
  Input: height = [1,1]
  Output: 1
   
  Constraints:
  n == height.length
  2 <= n <= 105
  0 <= height[i] <= 104

  LeetCode LInk: https://leetcode.com/problems/container-with-most-water/
*/
class Solution {
public:
  int maxArea(vector<int>& height) {
    size_t left = 0;
    size_t right = height.size() - 1;
    auto max_area = 0;
    while (left < right) {
      auto width = right - left;    // Calculate the width of the container.
      auto minimum_height = min(height[left], height[right]);  // Find the minimum height of the two walls
      auto current_area = width * minimum_height;  // Calculate the current area.
      max_area = max(max_area, current_area);  // Update the maximum area if the current area is larger. 

      // Move the pointer pointing to the shorter wall inward, as a taller wall will not increase the area. 
      height[left] < height[right] ? ++left : --right;
    }

    return max_area;
  }
};
