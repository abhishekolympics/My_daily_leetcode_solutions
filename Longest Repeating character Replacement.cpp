//watch this https://www.youtube.com/watch?v=00FmUN1pkGE

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>char_count(26,0);
        int max_length=0;
        int max_count=0;
        int window_start=0;
        for(int i=0;i<s.size();i++)
        {
            char_count[s[i]-'A']++;
            max_count=max(max_count,char_count[s[i]-'A']);
            //number of different character between the window = window_end - window_start - max_counts + 1
            while(i-window_start - max_count +1 > k)
            {
                char_count[s[window_start]-'A']--;
                window_start++;
            }
            max_length=max(max_length,i-window_start+1);
        }
        return max_length;
    }
};