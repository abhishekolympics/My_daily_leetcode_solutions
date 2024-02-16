class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>map(128,0);
        for(char c:t)
        {
            map[c]++;
        }
        int counter=t.size(),d=INT_MAX,start=0,end=0,head=0;
        while(end<s.size())
        {
            if(map[s[end++]]-- > 0)
            {
                counter--;
            }
            while(counter == 0)
            {
                if(end-start <d)
                {
                    head=start;
                    d=end-head;
                }
                if(map[s[start++]]++ == 0)
                {
                    counter++;
                }
            }
        }

        return d == INT_MAX ?"": s.substr(head,d);
    }
};