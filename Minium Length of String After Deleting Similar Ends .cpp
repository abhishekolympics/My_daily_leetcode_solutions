class Solution {
public:
    int minimumLength(string s) {
        char prev;
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                prev=s[i];
                s.erase(s.begin()+j);
                s.erase(s.begin());
                j=s.size()-1;
            }
            else if(s[i]==prev)
            {
                s.erase(s.begin());
                j=s.size()-1;
            }
            else if(s[j]==prev)
            {
                s.erase(s.begin()+j);
                j=s.size()-1;
            }
            else
            {
                break;
            }
        }
        if(s.size()==1 && s[0]==prev)
            s.erase(s.begin());
        return s.size();
    }
};
