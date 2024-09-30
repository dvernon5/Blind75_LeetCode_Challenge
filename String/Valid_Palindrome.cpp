/* 125. Valid Palindrome
  A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
  Alphanumeric characters include letters and numbers.
  
  Given a string s, return true if it is a palindrome, or false otherwise.

  Example 1:
  Input: s = "A man, a plan, a canal: Panama"
  Output: true
  Explanation: "amanaplanacanalpanama" is a palindrome.
  
  Example 2:
  Input: s = "race a car"
  Output: false
  Explanation: "raceacar" is not a palindrome.
  
  Example 3:
  Input: s = " "
  Output: true
  Explanation: s is an empty string "" after removing non-alphanumeric characters.
  Since an empty string reads the same forward and backward, it is a palindrome.

  Constraints:
  1 <= s.length <= 2 * 105
  s consists only of printable ASCII characters.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        string alphanumeric_string = getAlphanumericString(s);

        return isPalindromeHelper(alphanumeric_string) ? true : false;
    }

private:
    string getAlphanumericString(string& s) {
        int length = s.length();
        string alphanumeric_string = "";
        for (int i = 0; i < length; i++) {
            if (isalpha(s[i]) || isdigit(s[i])) {
                alphanumeric_string += s[i];
            }
        }
        transform(alphanumeric_string.begin(), alphanumeric_string.end(), alphanumeric_string.begin(), ::tolower);

        return alphanumeric_string;
    }

    bool isPalindromeHelper(string& charDigits) {
        string original_string = charDigits;
        reverse(charDigits.begin(), charDigits.end());
        
        return original_string == charDigits;
    }
};
