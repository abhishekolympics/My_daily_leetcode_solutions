class Solution {
public:
    // TC=O(N*M*4^L) where n= rows m=columns L=length of word
    // bool isWordExists(vector<vector<char>>& board, string word, int wordIndex, int i,int j, int m, int n)
    // {
    //     if(wordIndex==word.size())  return true;

    //     if(i<0 || j<0 ||i>=m || j>=n || board[i][j]!=word[wordIndex])
    //         return false;
    //     char temp=board[i][j];
    //     board[i][j]='*';
    //     bool ans1=isWordExists(board,word,wordIndex+1,i+1,j,m,n);
    //     bool ans2=isWordExists(board,word,wordIndex+1,i,j+1,m,n);
    //     bool ans3=isWordExists(board,word,wordIndex+1,i-1,j,m,n);
    //     bool ans4=isWordExists(board,word,wordIndex+1,i,j-1,m,n);

    //     board[i][j]=temp;

    //     return ans1||ans2||ans3||ans4;
    // }
    // bool exist(vector<vector<char>>& board, string word) {
    //     int m=board.size(),n=board[0].size();
    //     for(int i=0;i<m;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             if(board[i][j]==word[0] && isWordExists(board,word,0,i,j,m,n))
    //             {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    //TC=O(N*M*L) where n= rows m=columns L=length of word
    //WATCH https://www.youtube.com/watch?v=whyax_vB8xY
    int m,n;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool isWordExists(vector<vector<char>>& board, string& word, int wordIndex, int i,int j)
    {
        if(wordIndex==word.size())  return true;

        if(i<0 || j<0 ||i>=m || j>=n || board[i][j]!=word[wordIndex] || board[i][j]=='*')
            return false;

        char temp=board[i][j];
        board[i][j]='*';

        for(auto &dir:directions)
        {
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(isWordExists(board,word,wordIndex+1,new_i,new_j))
            {
                return true;
            }
        }
        board[i][j]=temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0] && isWordExists(board,word,0,i,j))
                {
                    return true;
                }
            }
        }
        return false;
    }


};
