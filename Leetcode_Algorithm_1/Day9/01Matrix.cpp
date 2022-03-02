/*
Problem: https://leetcode.com/problems/01-matrix/

542. 01 Matrix
Medium

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.
*/

class Solution {
public:
    bool checkvalid(int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int i, j;
        queue<pair<int, int>> q;
        vector<vector<int>> ans(m, vector<int> (n, -1));
        
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            
            if(checkvalid(i+1, j, m, n) && ans[i+1][j] == -1){
                q.push({i+1, j});
                ans[i+1][j] = ans[i][j] + 1;
            }
            if(checkvalid(i-1, j, m, n) && ans[i-1][j] == -1){
                q.push({i-1, j});
                ans[i-1][j] = ans[i][j] + 1;
            }
            if(checkvalid(i, j+1, m, n) && ans[i][j+1] == -1){
                q.push({i, j+1});
                ans[i][j+1] = ans[i][j] + 1;
            }
            if(checkvalid(i, j-1, m, n) && ans[i][j-1] == -1){
                q.push({i, j-1});
                ans[i][j-1] = ans[i][j] + 1;
            }
            q.pop();
        }
        return ans;
    }
};