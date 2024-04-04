class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int>res,new_res;
        
        for(auto it=mp.rbegin();it!=mp.rend();it++)
        {

        }
        sort(res.begin(),res.end());
        for(int i=k;i>0;i--)
        {
            new_res.push_back(res)
        }
        return res;
    }
};