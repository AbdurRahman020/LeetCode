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

