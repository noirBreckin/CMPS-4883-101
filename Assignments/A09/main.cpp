#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Store all events: (x, height, start/end)
        vector<pair<int, int>> events;
        for (const auto& building : buildings) {
            events.emplace_back(building[0], -building[2]); // Start of a building
            events.emplace_back(building[1], building[2]);  // End of a building
        }

        // Sort events: first by x, then by height
        sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        // Max-heap to store active heights
        multiset<int> heights = {0};
        vector<vector<int>> result;
        int prevMaxHeight = 0;

        for (const auto& event : events) {
            int x = event.first;
            int h = event.second;

            if (h < 0) {
                // Starting a building
                heights.insert(-h);
            } else {
                // Ending a building
                heights.erase(heights.find(h));
            }

            int currMaxHeight = *heights.rbegin(); // Max height in the current skyline

            if (currMaxHeight != prevMaxHeight) {
                result.push_back({x, currMaxHeight});
                prevMaxHeight = currMaxHeight;
            }
        }

        return result;
    }
};
