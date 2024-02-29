class Solution {
public:
    void bfs(int row,int col,vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty())
        {
            int row1=q.front().first;
            int col1=q.front().second;
            q.pop();
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (const auto& dir : directions) {
                int newRow = row1 + dir.first;
                int newCol = col1 + dir.second;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0,rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>vis(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};