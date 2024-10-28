class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
         int rows = board.size();
        int cols = board[0].size();
        
        // Directions for the eight neighbors
        vector<int> directions = {-1, 0, 1}; // For rows and cols

        // Create a copy of the board to determine the next state
        vector<vector<int>> copy = board;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int liveNeighbors = 0;

                // Count live neighbors
                for (int dr : directions) {
                    for (int dc : directions) {
                        if (dr == 0 && dc == 0) continue; // Skip the cell itself
                        int newRow = r + dr;
                        int newCol = c + dc;
                        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                            liveNeighbors += copy[newRow][newCol] == 1;
                        }
                    }
                }

                // Apply the rules
                if (copy[r][c] == 1) {
                    // Rule 1 or 3
                    board[r][c] = (liveNeighbors == 2 || liveNeighbors == 3) ? 1 : 0;
                } else {
                    // Rule 4
                    board[r][c] = (liveNeighbors == 3) ? 1 : 0;
                }
            }
        }
    }
};
