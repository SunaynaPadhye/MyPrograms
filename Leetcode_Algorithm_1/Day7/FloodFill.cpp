/*
Problem: https://leetcode.com/problems/flood-fill/submissions/

733. Flood Fill
Easy

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and newColor. 
You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]

Constraints:

    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], newColor < 216
    0 <= sr < m
    0 <= sc < n
*/

class Solution {
public:
    void floodFillRec(vector<vector<int>>& image, int x, int y, int newColor, int orgColor){
        if(x < 0 || y < 0 || x >= image.size() || y >= image[x].size())         //out of boundaries of image
            return;
        if(image[x][y] != orgColor)
            return;
        if(image[x][y] == newColor)
            return;
        
        image[x][y] = newColor;
        floodFillRec(image, x-1, y, newColor, orgColor);            //gong in 4 directions to fill new color
        floodFillRec(image, x+1, y, newColor, orgColor);
        floodFillRec(image, x, y-1, newColor, orgColor);
        floodFillRec(image, x, y+1, newColor, orgColor);

        return;     
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int orgColor = image[sr][sc];
        
        floodFillRec(image, sr, sc, newColor, orgColor);
        return image;
    }
};