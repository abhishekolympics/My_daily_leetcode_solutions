// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         return helper(nums, target);
//     }
    
//     int helper(const vector<int>& nums, int target) {
//         if (target == 0) {
//             return 1;
//         }
        
//         int count = 0;
//         for (int num : nums) {a
//             if (target - num >= 0) {
//                 count += helper(nums, target - num);
//             }
//         }
//         return count;
//     }
// }
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        std::unordered_map<int, int> memo;
        return helper(nums, target, memo);
    }
    
    int helper(const vector<int>& nums, int target, std::unordered_map<int, int>& memo) 
    {
        if (target == 0) 
        {
            return 1;
        }
        
        if (memo.find(target) != memo.end()) 
        {
            return memo[target];
        }
        
        int count = 0;
        for (int num : nums) 
        {
            if (target - num >= 0) 
            {
                count += helper(nums, target - num, memo);
            }
        }
        
        memo[target] = count;
        return count;
    }
};
