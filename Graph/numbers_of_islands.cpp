/*Problem Statement:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        unsigned int totalIslands = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1') {
                    totalIslands++;
                    dfs(grid, row, col);
                }
            }
        }

        return totalIslands;
    }

private:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        // Determine if location direction adjacency are valid.
        bool validDirection = (row < 0 || row >= m) || (col < 0 || col >= n) || grid[row][col] == '0';
        if (validDirection) { return; }

        // If direction is permitted, mark location as visited.
        grid[row][col] = '0';

        // Use Recursion to traverse through the grid in all four direction (right, left, top, bottom).
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }
};
