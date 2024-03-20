//watch this video for better understanding
//https://www.youtube.com/watch?v=T-Oj2Ajj9vA

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dic(256,-1);
        int maxLength=0,start=-1;
        for(int i=0;i<s.size();i++)
        {
            if(dic[s[i]]>start)
                start=dic[s[i]];
            dic[s[i]]=i;
            maxLength=max(maxLength,i-start);
        }
        return maxLength;
    }
};
