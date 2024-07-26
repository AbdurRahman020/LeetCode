#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // initialize the distance matrix with infinity
        vector<vector<int>> distance_matrix(n, vector<int>(n, INT_MAX));
        
        // distance from each city to itself is zero
        for (int city = 0; city < n; ++city) {
            distance_matrix[city][city] = 0;
        }

        // populate the distance matrix with the given edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            distance_matrix[u][v] = wt;
            distance_matrix[v][u] = wt;
        }

        // Floyd-Warshall algorithm to compute shortest paths between all pairs of cities
        for (int intermediate = 0; intermediate < n; ++intermediate) {
            for (int source = 0; source < n; ++source) {
                for (int destination = 0; destination < n; ++destination) {
                    if (distance_matrix[source][intermediate] != INT_MAX && 
                        distance_matrix[intermediate][destination] != INT_MAX) {
                        distance_matrix[source][destination] = min(
                            distance_matrix[source][destination],
                            distance_matrix[source][intermediate] + distance_matrix[intermediate][destination]
                        );
                    }
                }
            }
        }

        // variables to determine the best city
        int best_city = -1;
        int min_reachable_cities = n + 1;

        // evaluate each city to count how many cities are reachable within the distance threshold
        for (int city = 0; city < n; ++city) {
            int reachable_count = 0;
            for (int other_city = 0; other_city < n; ++other_city) {
                if (distance_matrix[city][other_city] <= distanceThreshold) {
                    ++reachable_count;
                }
            }
            
            // update the best city if the current city has fewer or equal reachable cities
            if (reachable_count <= min_reachable_cities) {
                min_reachable_cities = reachable_count;
                best_city = city;
            }
        }

        // return the city with the minimum number of reachable cities within the distance threshold
        return best_city;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges1 = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout << s.findTheCity(4, edges1, 4) << endl;
    vector<vector<int>> edges2 = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    cout << s.findTheCity(5, edges2, 2) << endl;
    return 0;
}