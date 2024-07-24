#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // lambda function to compute the mapped value based on mapping
        auto map_to_sorted_value = [&](int num) -> int {
            if (num == 0) {
                return mapping[0];
            }
            
            int mapped_value = 0;
            int power_of_10 = 1;
            
            while (num > 0) {
                // get the last digit of num
                int r = num % 10;
                // remove the last digit from num
                num /= 10;
                // map the digit using mapping and accumulate
                mapped_value += mapping[r] * power_of_10;
                // increment power of 10 for next digit
                power_of_10 *= 10;
            }
            
            return mapped_value;
        };

        // vector to store mapped values along with original indices and numbers
        vector<pair<int, pair<int, int>>> num_map;
        // populate num_map with mapped values, original indices, and original numbers
        for (int i = 0; i < nums.size(); ++i) {
            num_map.push_back({map_to_sorted_value(nums[i]), {i, nums[i]}});
        }
        // sort num_map based on the mapped values
        sort(num_map.begin(), num_map.end());
        // prepare the result vector to store sorted original numbers
        vector<int> sorted_nums(nums.size());
        // extract sorted original numbers from num_map
        for (int i = 0; i < nums.size(); ++i) {
            sorted_nums[i] = num_map[i].second.second;
        }
        // return the sorted numbers
        return sorted_nums;
    }
};

int main() {
    Solution s;
    vector<int> mapping1 = {8,9,4,0,2,1,3,5,7,6};
    vector<int> nums1 = {991, 338, 38};
    vector<int> result1 = s.sortJumbled(mapping1, nums1);
    for (int num : result1) {
        cout << " " << num;
    }
    cout << endl;
    vector<int> mapping2 = {0,1,2,3,4,5,6,7,8,9};
    vector<int> nums2 = {789, 456, 123};
    vector<int> result2 = s.sortJumbled(mapping2, nums2);
    for (int num : result2) {
        cout << " " << num;
    }
    cout << endl;
    return 0;
}