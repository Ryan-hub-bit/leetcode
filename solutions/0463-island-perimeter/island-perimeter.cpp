// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
//
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
//
// The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
//
//  
//
// Example:
//
//
// Input:
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]
//
// Output: 16
//
// Explanation: The perimeter is the 16 yellow stripes in the image below:
//
//
//
//


class Solution {
public:
    int findWholeIsland(vector<vector<int> > & grid, vector<vector<int> > & vis, int x, int y){
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        int m = grid.size(), n = grid[0].size();
        vis[x][y] = 1;
        int ans = 0;
        for(int k = 0;k < 4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && vis[nx][ny] == 0){
                ans += findWholeIsland(grid, vis, nx, ny);
            }else if(!(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)){
                ans++;
            }
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans += findWholeIsland(grid, vis , i, j);
                }
            }
        }
        return ans;
    }
};
