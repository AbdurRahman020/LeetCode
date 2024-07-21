#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // function for topological sort
        auto topological_sort = [&](vector<vector<int>>& edges, int k) -> vector<int> {
            // initialize predecessor map to store predecessors
            unordered_map<int, vector<int>> pred_map;
            // initialize in-degree array to store in-degree of each node
            vector<int> in_degree(k + 1, 0);
            
            // build the predecessor map and in-degree array
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1];
                pred_map[u].push_back(v);
                in_degree[v]++;
            }
            
            // initialize queue with nodes having zero in-degree
            queue<int> q;
            for (int i = 1; i <= k; ++i) {
                if (in_degree[i] == 0) {
                    q.push(i);
                }
            }
            
            // vector to store the topological order
            vector<int> topological_order;
            
            // perform topological sorting using Kahn's algorithm
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                topological_order.push_back(node);
                
                // decrease in-degree of neighbors and enqueue if in-degree becomes zero
                for (int neighbor : pred_map[node]) {
                    in_degree[neighbor]--;
                    if (in_degree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            
            // if the order contains all nodes (k nodes), return the order
            if (topological_order.size() == k) {
                return topological_order;
            } else {
                // return empty vector if not all nodes are included
                return {};
            }
        };
        
        // function to fix positions based on topological order
        auto fix_position = [&](vector<int>& topological_order) -> unordered_map<int, int> {
            // map node to its position in order
            unordered_map<int, int> pos_map;
            for (int i = 0; i < topological_order.size(); ++i) {
                pos_map[topological_order[i]] = i;
            }
            
            // next available position
            int next_pos = topological_order.size();
            
            // fill positions for nodes not present in the order
            for (int node = 1; node <= k; ++node) {
                if (pos_map.find(node) == pos_map.end()) {
                    pos_map[node] = next_pos++;
                }
            }
            
            return pos_map;
        };
        
        // perform topological sorting on row and column conditions
        auto row_order = topological_sort(rowConditions, k);
        auto col_order = topological_sort(colConditions, k);
        
        // if either row or column order is empty, return empty matrix
        if (row_order.empty() || col_order.empty()) {
            return {};
        }
        
        // fix positions for rows and columns
        unordered_map<int, int> row_positions = fix_position(row_order);
        unordered_map<int, int> col_positions = fix_position(col_order);
        
        // initialize matrix with zeros
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        
        // fill matrix based on fixed row and column positions
        for (int node = 1; node <= k; ++node) {
            matrix[row_positions[node]][col_positions[node]] = node;
        }
        
        // return the constructed matrix
        return matrix;
    }
};

int main() {
    Solution s;

    vector<vector<int>> rowConditions1 = {{1,2},{3,2}};
    vector<vector<int>> colConditions1 = {{2,1},{3,2}};
    auto result1 = s.buildMatrix(3, rowConditions1, colConditions1);
    for (auto& row : result1) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<vector<int>> rowConditions2 = {{1,2},{2,3},{3,1},{2,3}};
    vector<vector<int>> colConditions2 = {{2,1}};
    auto result2 = s.buildMatrix(3, rowConditions2, colConditions2);
    for (auto& row : result2) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}