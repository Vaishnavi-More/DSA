//Leetcode: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
//LINK: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     //generate 2D matrix
                     vector<vector<int>> matrix(n, vector<int>(m,1e9));
                     for(auto it:edges){
                         matrix[it[0]][it[1]]=it[2];
                         matrix[it[1]][it[0]]=it[2];
                     }
                     
                     //store 0 at index 11, 22, 33...
                     for(int i=0; i<n; i++){
                         matrix[i][i]=0;
                     }
                     
                     //Floyd Warshall Algo to find shortest path
                     for(int k=0; k<n; k++){
                         for(int i=0; i<n; i++){
                             for(int j=0; j<n; j++){
                                 if(matrix[i][k]==INT_MAX || matrix[k][j]==INT_MAX) continue;
                                 matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                             }
                         }
                     }
                     
                     //traverse matrix to find no of cities 
                     int max_cnt=n;
                     int city=-1;
                     for(int i=0; i<n; i++){
                         int count=0;
                         for(int j=0; j<n; j++){
                             if(matrix[i][j]<=distanceThreshold) count++;
                         }
                         if(count<=max_cnt){
                             max_cnt=count;
                             city=i;
                         }
                     }
                     return city;
                 }

//TC: O(V^3)
//SC: O(V^2)
