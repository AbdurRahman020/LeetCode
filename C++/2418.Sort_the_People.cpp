#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // get number of elements in names vector
        int n = names.size();

        // create a vector of pairs (height, name)
        vector<pair<int, string>> people_list;
        for (int i = 0; i < n; ++i) {
            people_list.push_back({heights[i], names[i]});
        }

        // sort the vector of pairs in descending order based on height
        sort(people_list.begin(), people_list.end(), greater<pair<int, string>>());

        // extract sorted names from the sorted vector of pairs
        vector<string> sorted_names;
        for (auto& person : people_list) {
            sorted_names.push_back(person.second);
        }

        // return the sorted names vector
        return sorted_names;
    }
};

int main() {
    Solution s;

    vector<string> names1 = {"Mary", "John", "Emma"};
    vector<int> heights1 = {180, 165, 170};
    vector<string> sorted_names1 = s.sortPeople(names1, heights1);
    for (const auto& name : sorted_names1) {
        cout << name << " ";
    }
    cout << endl;
    
    vector<string> names2 = {"Alice", "Bob", "Bob"};
    vector<int> heights2 = {155, 185, 150};
    vector<string> sorted_names2 = s.sortPeople(names2, heights2);
    for (const auto& name : sorted_names2) {
        cout << name << " ";
    }
    cout << endl;

    return 0;
}