/*Problem Statement:
  Given two integers a and b, return the sum of the two integers without using the operators + and -.
  
  Example 1:
  Input: a = 1, b = 2
  Output: 3
  
  Example 2:
  Input: a = 2, b = 3
  Output: 5
   
  Constraints:
  -1000 <= a, b <= 1000

  LeetCode Link: https://leetcode.com/problems/sum-of-two-integers/
*/
int getSum(int a, int b) {
  while (b != 0) {
    int carry = a & b;  // Calculate the carry.
    a = a ^ b;  // Sum without carry.
    b = carry << 1;  // Shift the carry to the left.
  }

  return a;
}
