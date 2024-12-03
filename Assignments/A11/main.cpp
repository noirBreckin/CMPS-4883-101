#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, int color, vector<int>& colors, vector<vector<int>>& graph) {
        colors[node] = color;
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == color) {
                return false; // Conflict detected
            }
            if (colors[neighbor] == 0 && !dfs(neighbor, -color, colors, graph)) {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (const auto& dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }

        vector<int> colors(n + 1, 0); // 0: uncolored, 1: group 1, -1: group 2
        for (int i = 1; i <= n; ++i) {
            if (colors[i] == 0 && !dfs(i, 1, colors, graph)) {
                return false;
            }
        }
        return true;
    }
};
