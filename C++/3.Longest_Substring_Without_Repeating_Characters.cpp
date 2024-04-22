#include <iostream>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int pos = -1, result = 0;
        std::unordered_map<char, int> count;
        for (int i = 0; i < s.length(); i++) {
            if (count.find(s[i]) != count.end() && count[s[i]] > pos) {
                pos = count[s[i]];
            }
            count[s[i]] = i;
            result = std::max(result, i - pos);
        }
        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << s.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    return 0;
}