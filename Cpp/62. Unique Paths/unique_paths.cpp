
// Source : https://leetcode.com/problems/unique-paths/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: 
//    v1: only upper or left grid can reach the final location in 1 step.
//        d(m,n) = d(m-1,n) + d(m,n-1), with boundary condition: d(1,:) = 1, d(:,1) = 1.
//        iterate row by row

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
          return 1;   
        } else {
            vector<vector<int>> d;
            vector<int> temp(n);
            int i,j;
            for (i = 0; i < m; i++) {
                d.push_back(temp);
            }
            //initialize the boundary
            for (i=0;i<m;i++) {
                d[i].at(0) = 1;
            }
            for (j=0;j<n;j++) {
                d[0].at(j) = 1;
            }
            
            for(i = 1; i < m; i++) {
                //(i+1)-th row
                for (j = 1; j < n; j++) {
                    //(j+1)-th column
                    d[i].at(j) = d[i - 1].at(j) + d[i].at(j - 1);
                }
            }
            return d[m - 1].at(n - 1);
        }        
    }
};
