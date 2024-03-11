class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int top=0,left=0,bottom=matrix.size()-1,right=matrix[0].size()-1;
        while(top<=bottom && left<=right)
        {
            cout<<"top="<<top<<" left="<<left<<" bottom="<<bottom<<" right="<<right<<endl;
            for(int i=left;i<=right;i++)
            {
                cout<<"first"<<endl;
                cout<<matrix[top][i]<<endl;
                res.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                cout<<"first2"<<endl;
                cout<<matrix[i][right]<<endl;
                res.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                cout<<"first3"<<endl;
                    cout<<matrix[bottom][i]<<endl;
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                cout<<"first4"<<endl;
                    cout<<matrix[i][left]<<endl;
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};