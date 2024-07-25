#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // call merge_sort function to sort the input nums array
        return mergeSort(nums);
    }
    
private:
    vector<int> mergeSort(vector<int>& arr) {
        int n = arr.size();
        
        // base case: if the array has only one element, it's already sorted
        if (n <= 1) {
            return arr;
        }
        
        // divide the array into two halves
        int mid = n / 2;
        
        vector<int> left_arr(arr.begin(), arr.begin() + mid);
        vector<int> right_arr(arr.begin() + mid, arr.end());
        
        // recursively sort the left and right halves
        left_arr = mergeSort(left_arr);
        right_arr = mergeSort(right_arr);
        
        // merge the sorted halves
        return merge(left_arr, right_arr);
    }
    
    vector<int> merge(vector<int>& left_arr, vector<int>& right_arr) {
        // initialize an empty list to store merged result
        vector<int> merged_arr;
        // initialize pointers for left_arr and right_arr
        int i = 0, j = 0;
        // lengths of left_arr and right_arr
        int m = left_arr.size(), n = right_arr.size();
        
        // merge the two sorted arrays into a single sorted array
        while (i < m && j < n) {
            if (left_arr[i] <= right_arr[j]) {
                merged_arr.push_back(left_arr[i]);
                i++;
            } else {
                merged_arr.push_back(right_arr[j]);
                j++;
            }
        }
        
        // append remaining elements
        while (i < m) {
            merged_arr.push_back(left_arr[i]);
            i++;
        }
        while (j < n) {
            merged_arr.push_back(right_arr[j]);
            j++;
        }
        
        // return the merged and sorted array
        return merged_arr;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {5, 2, 3, 1};
    vector<int> sorted1 = s.sortArray(nums1);
    for (int num : sorted1) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> nums2 = {5, 1, 1, 2, 0, 0};
    vector<int> sorted2 = s.sortArray(nums2);
    for (int num : sorted2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}