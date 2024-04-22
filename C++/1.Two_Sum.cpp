#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> checked;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (checked.find(diff) != checked.end()) {
                return {checked[diff], i};
            } else {
                checked[nums[i]] = i;
            }
        }
        return {};
    }
};

int main() {
    Solution l;
    std::vector<int> result1 = l.twoSum({2, 7, 11, 15}, 9);
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> result2 = l.twoSum({3, 2, 4}, 6);
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> result3 = l.twoSum({-1, -2, -3, -4, -5}, -8);
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}