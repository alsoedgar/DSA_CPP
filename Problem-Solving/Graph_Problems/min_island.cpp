#include <iostream>
#include <vector>
#include <climits>   // for INT_MAX
#include <algorithm> // for std::min

class IslandProblems {
private:
    // Helper DFS that returns the size (cell count) of the explored island
    int exploreSize(std::vector<std::vector<char>>& grid, int r, int c) {
        // 1. Base cases: Out of bounds or hitting water ('0')
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0') {
            return 0;
        }

        // 2. Sink the land cell to mark it visited
        grid[r][c] = '0';

        // 3. This current cell contributes 1 to the size
        int size = 1;

        size += exploreSize(grid, r-1, c);
        size += exploreSize(grid, r+1, c);
        size += exploreSize(grid, r, c-1);
        size += exploreSize(grid, r, c+1);
        return size;
    }

public:
    int minIslandSize(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) return 0;

        // Initialize minSize to the largest possible integer
        int minSize = INT_MAX; 
        bool foundIsland = false;

        // Loop through every single coordinate in the grid
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == '1'){
                    foundIsland = true;
                    int size = exploreSize(grid, r, c);
                    minSize = std::min(size, minSize);
                }
            }
        }

        // If we went through the whole grid and never hit a '1', return 0
        return foundIsland ? minSize : 0;
    }
};

int main() {
    IslandProblems solver;

    // Test Case:
    // Island 1: Top-left cluster (Size 4)
    // Island 2: Middle single cell (Size 1) <-- This is the minimum!
    // Island 3: Bottom-right cluster (Size 2)
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int result = solver.minIslandSize(grid);
    std::cout << "Size of the Minimum Island: " << result << std::endl;
    std::cout << "Test: " << (result == 1 ? "PASSED (1)" : "FAILED") << std::endl;

    return 0;
}