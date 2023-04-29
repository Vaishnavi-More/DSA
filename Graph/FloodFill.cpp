//Leetcode: 733. Flood Fill
//Link: https://leetcode.com/problems/flood-fill/

void help(vector<vector<int>>& image, int i, int j, int oldcolor, int newcolor , int n, int m){
    
        //base case
        if(i<0 || j<0 || i==n || j==m || image[i][j]!=oldcolor) return;
        
        //colour the current cell 
        image[i][j]=newcolor;

        //recursive call

        //down
        help(image, i+1, j, oldcolor, newcolor, n, m);

        //up
        help(image, i-1, j, oldcolor, newcolor, n, m);

        //right
        help(image, i, j+1, oldcolor, newcolor, n, m);

        //left
        help(image, i, j-1, oldcolor, newcolor, n, m);


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor=image[sr][sc];
        if(oldcolor==color) return image;
        help(image, sr, sc, oldcolor, color, image.size(), image[0].size());
        return image;
    }

//Time Complexity: O(N *M)  ..where N is no of rows & M is no of columns
//Space Complexity: O(N*M)  ..stack space aquired
