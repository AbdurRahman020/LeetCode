#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s == std::string(s.rbegin(), s.rend())) {
            return s;
        }

        std::string result;
        int len_result = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            int left, right;
            left = i;
            right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > len_result) {
                    result = s.substr(left, right - left + 1);
                    len_result = right - left + 1;
                }
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > len_result) {
                    result = s.substr(left, right - left + 1);
                    len_result = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.longestPalindrome("babad") << std::endl;
    std::cout << s.longestPalindrome("cbbd") << std::endl;
    return 0;
}
