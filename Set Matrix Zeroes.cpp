class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool row0=false,col0=false;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(i==0 && matrix[i][j]==0)
                {
                    col0=true;
                }
                if(j==0 && matrix[i][j]==0)
                {
                    row0=true;
                }
            }
        }
        cout<<"row0="<<row0<<" co0"<<col0<<endl;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            if(row0==true)
            {
                matrix[i][0]=0;
            }
        }
        for(int j=0;j<matrix[0].size();j++)
        {
            if(col0==true)
            {
                matrix[0][j]=0;
            }
        }
    }
};