class Solution {
public:
    bool search(vector<int>& nums,int x)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(x==nums[i])
            {
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        //brute force
        //we'll first stick to 1 element and check
        // for its next element

        int longest=0,x=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            int count=1;
            while(search(nums,x+1)==true)
            {
                count++;
                x++;
            }
            longest=max(longest,count);
        }
        return longest;
    }

    store all elements in a set and check for the next and previous elements
     int longestConsecutive(vector<int>& nums) {
         if(nums.empty()) return 0;
         unordered_set<int>st;
         int n=nums.size(),longest=1;
         for(int i=0;i<n;i++)
         {
             st.insert(nums[i]);
         }
         for(int i=0;i<n;i++)
         {
             if(st.find(nums[i]-1)==st.end())
             {
                 int x=nums[i];
                 int count=1;
                 while(st.find(x+1)!=st.end())
                 {
                     count++;
                     x++;
                 }
                 longest=max(longest,count);
             }
         }
         return longest;
     }

    // optimized approach
    // we can use a graph to store every element
    // we can use a visited array to store the array
    // TC=O(n)
    // SC=O(n)
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_map<int, bool> vis;
        int longest = 0, count = 0, vtx = 0;
        queue<int> q;
        for (int num : nums) {
            vis[num] = false;
        }
        for (int num : nums) {
            if (vis.count(num) && !vis[num]) {
                q.push(num);
                vis[num] = true;

                count = 0;
                while (!q.empty()) {
                    vtx = q.front();
                    q.pop();

                    count++;

                    if (vis.count(vtx + 1) && !vis[vtx + 1]) {
                        vis[vtx + 1] = true;
                        q.push(vtx + 1);
                    }
                    if (vis.count(vtx - 1) && !vis[vtx - 1]) {
                        vis[vtx - 1] = true;
                        q.push(vtx - 1);
                    }
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};