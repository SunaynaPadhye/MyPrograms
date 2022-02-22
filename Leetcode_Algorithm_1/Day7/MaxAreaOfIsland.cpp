/*
Problem: https://leetcode.com/problems/max-area-of-island/

695. Max Area of Island
Medium

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    grid[i][j] is either 0 or 1.

*/

class Solution {
public:
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y){
        if(grid[x][y] == 0 || visited[x][y] == 1)
            return 0;
        int area = 1;
        visited[x][y] = 1;
        if(x > 0)
            area += dfs(grid, visited, x-1, y);
        if(x+1 < grid.size())
            area += dfs(grid, visited, x+1, y);
        if(y > 0)
            area += dfs(grid, visited, x, y-1);
        if(y+1 < grid[0].size())
            area += dfs(grid, visited, x, y+1);
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i, j;
        
        vector<vector<int>> visited(m, vector<int>(n));
        int area = 0;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                area = max(area, dfs(grid, visited, i, j));
            }
        }
        return area;
    }
};

/*
This solution uses dfs (depth first search).
*/