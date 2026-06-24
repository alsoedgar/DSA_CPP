#include <iostream>
#include <vector>

class IslandProblems {
private:
    // Helper DFS to explore and "sink" an entire island
    void destroyIsland(std::vector<std::vector<char>>& grid, int r, int c) {
        // 1. Base Cases: Out of bounds check or hitting water ('0')
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }

        // 2. Mark the current cell as visited by converting it to water
        grid[r][c] = '0';

        // 3. Recursively visit all 4 adjacent directions 
        // (Up, Down, Left, Right)
        destroyIsland(grid, r+1, c);
        destroyIsland(grid, r-1, c);
        destroyIsland(grid, r, c+1);
        destroyIsland(grid, r, c-1);
        
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int islandCount = 0;

        // Loop through every single coordinate in the grid
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                // 1. Increment islandCount
                // 2. Launch destroyIsland to clear the connected landmass
                if(grid[r][c] == '1'){
                    islandCount++;
                    destroyIsland(grid, r, c);
                }
                
            }
        }

        return islandCount;
    }
};

int main() {
    IslandProblems solver;

    // Test Case: A grid with 3 distinct islands
    // Island 1: Top-left cluster
    // Island 2: Middle single cell
    // Island 3: Bottom-right cluster
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int result = solver.numIslands(grid);
    std::cout << "Total Number of Islands: " << result << std::endl;
    std::cout << "Test: " << (result == 3 ? "PASSED (3)" : "FAILED") << std::endl;

    return 0;
}