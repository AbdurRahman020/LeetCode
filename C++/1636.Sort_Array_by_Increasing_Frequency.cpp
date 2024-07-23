#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // map to store frequency of each number
        unordered_map<int, int> freq;
        // count frequencies of each number in nums
        for (int n : nums) {
            freq[n]++;
        }

        // custom sort based on frequency and value
        sort(nums.begin(), nums.end(), [&](int num1, int num2) {
            // if frequencies are different, sort by increasing frequency
            if (freq[num1] != freq[num2]) {
                return freq[num1] < freq[num2];
            }
             // if frequencies are the same, sort by decreasing value
            return num1 > num2;
        });

        // return the sorted nums vector
        return nums;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {1,1,2,2,2,3};
    vector<int> sorted_nums1 = s.frequencySort(nums1);
    for (const auto& num1 : sorted_nums1) {
        cout << num1 << " ";
    }
    cout << endl;

    vector<int> nums2 = {2,3,1,3,2};
    vector<int> sorted_nums2 = s.frequencySort(nums2);
    for (const auto& num2 : sorted_nums2) {
        cout << num2 << " ";
    }
    cout << endl;
    
    vector<int> nums3 = {-1,1,-6,4,5,-6,1,4,1};
    vector<int> sorted_nums3 = s.frequencySort(nums3);
    for (const auto& num3 : sorted_nums3) {
        cout << num3 << " ";
    }
    cout << endl;

    return 0;
}