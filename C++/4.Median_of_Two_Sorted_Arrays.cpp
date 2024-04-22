#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::vector<int> num = nums1;
        num.insert(num.end(), nums2.begin(), nums2.end());
        std::sort(num.begin(), num.end());
        
        int n = num.size();
        if (n % 2 != 0) {
            return num[n / 2];
        } else {
            int m1 = num[(n - 1) / 2];
            int m2 = num[(n - 1) / 2 + 1];
            return (static_cast<double>(m1) + static_cast<double>(m2)) / 2;
        }
    }
};

int main() {
    Solution s;
    std::cout << s.findMedianSortedArrays({1, 3}, {2}) << std::endl;
    std::cout << s.findMedianSortedArrays({1, 2}, {3, 4}) << std::endl;
    return 0;
}