#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string string = std::to_string(x);
        std::string r_string = std::string(string.rbegin(), string.rend());
        if (string == r_string) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
    std::cout << s.isPalindrome(121) << std::endl;
    std::cout << s.isPalindrome(-121) << std::endl;
    std::cout << s.isPalindrome(-10) << std::endl;
    return 0;
}