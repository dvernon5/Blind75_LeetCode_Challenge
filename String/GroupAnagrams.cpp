class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> anagramsGroup;
      for (const auto: str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramsGroup[sortedStr].push_back(str);
      }
      vector<vector<string>> result;
      for (const auto: group : anagramsGroup) {
        result.push_back(group.second);
      }

      retunr result;
    }
};
