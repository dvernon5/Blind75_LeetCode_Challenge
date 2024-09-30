/* 5. Longest Palindromic Substring
  Given a string s, return the longest palindromic substring in s.
  
  Example 1:
  Input: s = "babad"
  Output: "bab"
  Explanation: "aba" is also a valid answer.
  
  Example 2:
  Input: s = "cbbd"
  Output: "bb"
   
  Constraints:
  1 <= s.length <= 1000
  s consist of only digits and English letters.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        int start = 0;
        int maxLength = 1;
        int length = s.length();
        for (int i = 0; i < length; i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxLength) {
                start = i - (len - 1) / 2;
                maxLength = len;
            }
        }

        return s.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        int length = s.length();
        while (left >= 0 && right < length && s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }
};
