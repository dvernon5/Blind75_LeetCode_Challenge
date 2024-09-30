/* 3. Longest Substring Without Repeating Character.
  Given a string s, find the length of the longest substring without repeating characters.
  
  Example 1:
  Input: s = "abcabcbb"
  Output: 3
  Explanation: The answer is "abc", with the length of 3.
  
  Example 2:
  Input: s = "bbbbb"
  Output: 1
  Explanation: The answer is "b", with the length of 1.
  
  Example 3:
  Input: s = "pwwkew"
  Output: 3
  Explanation: The answer is "wke", with the length of 3.
  Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
  Constraints:
  0 <= s.length <= 5 * 104
  s consists of English letters, digits, symbols and spaces.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_index;
        int start = 0;
        int max_substring = 0;
        int length = s.length();
        for (int end = 0; end < length; end++) {
            char current_char = s[end];
            if (char_index.find(current_char) != char_index.end() &&
                char_index[current_char] >= start) {
                    start = char_index[current_char] + 1;
            }
            max_substring = max(max_substring, end - start + 1);
            char_index[current_char] = end;
        }

        return max_substring;
    }
};
