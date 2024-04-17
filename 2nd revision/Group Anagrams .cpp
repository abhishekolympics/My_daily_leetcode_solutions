//WATCH VIDEO https://www.youtube.com/watch?v=--k5-3EOObs


class Solution {
public:
    // BRUTE FORCE
    // TC=O(K * N * log(N))= O(KNlogN)
    //where K is number of words, n is the word length
    // SC=O(K * N)=O(KN)
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     int n=strs.size();
    //     unordered_map<string,vector<string>>mp;
    //     for(int i=0;i<n;i++)
    //     {
    //         string word=strs[i];
    //         sort(word.begin(),word.end());
    //         mp[word].push_back(strs[i]);
    //     }
    //     vector<vector<string>>ans;
    //     for(auto i:mp)
    //     {
    //         ans.push_back(i.second);
    //     }

    //     return ans;
    // }

    //Better approach
    // TC=O(NK)
    // SC=O(NK)

    string generate(string word)
    {
        int arr[26]={0};

        for(char ch:word)
        {
            arr[ch-'a']++;
        }

        string new_word="";

        for(int i=0;i<26;i++)
        {
            int freq= arr[i];

            if(freq>0)
            {
                new_word+=string(freq,i+'a');
            }
        }
        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++)
        {
            string word=generate(strs[i]);
            mp[word].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};
