/* 242. Valid Anagram
  Given two strings s and t, return true if t is an anagram of s, and false otherwise.
  
  Example 1:
  Input: s = "anagram", t = "nagaram"
  Output: true
  
  Example 2:
  Input: s = "rat", t = "car"
  Output: false
  
  Constraints:
  1 <= s.length, t.length <= 5 * 104
  s and t consist of lowercase English letters.
  
  Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();
        if (s_length != t_length) return false;
        unordered_map<char, int> charFreq;
        for (int i = 0; i < s_length; i++) {
            charFreq[s[i]]++;
        }
        for (int i = 0; i < t_length; i++) {
            charFreq[t[i]]--;
            if (charFreq[t[i]] < 0) {
                return false;
            }
        }

        return true;
    }
};
