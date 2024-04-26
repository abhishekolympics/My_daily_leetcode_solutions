//Watch this video for better understanding https://www.youtube.com/watch?v=Z0R2u6gd3GU
class Solution {
public:
    //BRUTE FORCE
    //create another matrix to store the correct matrix values
    //TC=O(n^2)
    //SC=O(n^2)
    // void rotate(vector<vector<int>>& matrix) {
    //     int n=matrix[0].size();
    //     int m=matrix.size();
    //     vector<vector<int>> res(m+1,vector<int>(n+1,0));
    //     for(int i=0;i<m;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             res[j][n-1-i]=matrix[i][j];
    //         }
    //     }
    //     for(int i=0;i<m;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             matrix[i][j]=res[i][j];
    //         }
    //     }

    // }

    //Optimized approach
    //first transpose the matrix and then reverse the columns
    //TC=O(n^2) 
    //SC=O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<=i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
