#include <iostream>
#include <string>
#include <cmath>

class Solution {
public:
    int reverse(int x) {
        long long int_reversed = 0;
        int sign = 1;
        
        if (x < 0) {
            sign = -1;
            x = -x;
        }

        while (x > 0) {
            int_reversed = int_reversed * 10 + x % 10;
            x /= 10;
        }

        int_reversed *= sign;

        if (int_reversed > std::pow(2, 31) - 1 || int_reversed < -std::pow(2, 31)) {
            return 0;
        }
        return int(int_reversed);
    }
};

int main() {
    Solution s;
    std::cout << s.reverse(-123) << std::endl;
    std::cout << s.reverse(1534236469) << std::endl;
    std::cout << s.reverse(120) << std::endl;
    return 0;
}
