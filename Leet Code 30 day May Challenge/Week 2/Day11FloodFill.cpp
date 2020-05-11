/********** Flood Fill*****************
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
**************************************/


/**************** Solution CPP ******************/
/* Recursive Approach*/
class Solution {
public:
    unsigned int row,column;
    int valid(unsigned int newi,unsigned int newj)
    {
        return (newi>=0 && newi<row)?((newj>=0 && newj<column)?1:0):0;
    }
    void fillColor(vector<vector<int>> &v,  int sr,  int sc , int newColor, int col,vector<vector<int>> &visited)
    {
        int direction[4][2] ={{0,-1},{0,1},{-1,0},{1,0}};
        for(int i=0;i<4;i++)
        {
            
            v[sr][sc] = newColor;
            visited[sr][sc] = 1;
            int newi = sr + direction[i][0];
            int newj = sc + direction[i][1];
            if(valid(newi,newj)== 1 && col == v[newi][newj] && visited[newi][newj] ==0 )
            {
                v[newi][newj] = newColor;
                fillColor(v,newi,newj,newColor,col,visited);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> v(image);
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        
        int col = v[sr][sc];
        row = image.size();    
        column = image[0].size();
        fillColor(v,sr,sc,newColor,col,visited);
        return v;
    }
};

