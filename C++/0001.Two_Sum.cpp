#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    // function to find indices of two numbers in the array that add up to the target
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        // map to store checked numbers and their indices
        std::unordered_map<int, int> checked;
        // size of the input vector
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // calculate the difference needed to reach the targe
            int diff = target - nums[i];
            // if the difference is found in the map
            if (checked.find(diff) != checked.end()) {
                // return the indices of the two numbers that sum up to the target
                return {checked[diff], i};
            } else {
                // store the current number and its index in the map
                checked[nums[i]] = i;
            }
        }
        // if no solution is found, return an empty vector
        return {};
    }
};

int main() {
    Solution s;
    std::vector<int> result1 = s.twoSum({2, 7, 11, 15}, 9);
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> result2 = s.twoSum({3, 2, 4}, 6);
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> result3 = s.twoSum({-1, -2, -3, -4, -5}, -8);
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}