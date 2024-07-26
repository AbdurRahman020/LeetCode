#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // variable to store the city with the minimum reachable cities within the threshold
        int best_city = -1;
        // initialize to a value larger than possible to find the minimum
        int min_reachable_cities = n + 1;
        // adjacency list to store the graph
        unordered_map<int, vector<pair<int, int>>> adj_list;

        // create adjacency list from the edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            // add edge from u to v with the given weight
            adj_list[u].emplace_back(v, weight);
            // add edge from v to u with the given weight (since undirected)
            adj_list[v].emplace_back(u, weight);
        }

        // iterate through each city to determine the number of reachable cities
        for (int city = 0; city < n; ++city) {
            // counter for the number of cities reachable within the distance threshold
            int reachable_count = 0;
            // distance array initialized to infinity
            vector<int> distances(n, INT_MAX);
            // distance to itself is 0
            distances[city] = 0;
            // priority queue for Dijkstra's algorithm, initialized with the starting city
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priority_queue;
            priority_queue.emplace(0, city);

            // Dijkstra's algorithm to find the shortest paths from the current city
            while (!priority_queue.empty()) {
                // get the city with the smallest distance
                auto [current_distance, current_city] = priority_queue.top();
                priority_queue.pop();

                // if the distance exceeds the threshold, no need to process further
                if (current_distance > distanceThreshold) {
                    break;
                }

                // explore all neighbors of the current city
                for (const auto& [neighbor_city, weight] : adj_list[current_city]) {
                    // calculate the distance to the neighbor city
                    if (current_distance + weight < distances[neighbor_city]) {
                        // update distance if a shorter path is found
                        distances[neighbor_city] = current_distance + weight;
                        // push the neighbor into the priority queue
                        priority_queue.emplace(distances[neighbor_city], neighbor_city);
                    }
                }
            }

            // count the number of cities within the distance threshold from the current city
            reachable_count = count_if(distances.begin(), distances.end(),
                [distanceThreshold](int dist) { return dist <= distanceThreshold; });

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

// Test cases
int main() {
    Solution s;
    vector<vector<int>> edges1 = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout << s.findTheCity(4, edges1, 4) << endl;
    vector<vector<int>> edges2 = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    cout << s.findTheCity(5, edges2, 2) << endl;
    return 0;
}