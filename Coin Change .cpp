class Solution {
public:
    // RECURSION
    // int helper(vector<int>& coins, int amount,int curr)
    // {
    //     if(curr>=coins.size() || amount<=0)
    //     {
    //         return (amount == 0)? 0 : INT_MAX - 1;
    //     }

    //     int res = -1;
    //     if(coins[curr]> amount)
    //     {
    //         int dont = 0 + helper(coins,amount-0,curr+1);
    //         res = dont;
    //     }
    //     else
    //     {
    //         int doo= 1+helper(coins,amount-coins[curr],curr+0);
    //         int dont = 0+helper(coins,amount+0,curr+1);
    //         res = min(doo,dont);
    //     }
    //     return res;
    // }
    // int coinChange(vector<int>& coins, int amount) {
    // int res = helper(coins,amount,0);
    // return (res == INT_MAX - 1) ? -1 : res;
    // }

    // RECURSION WITH MEMOIZATION
    int dp[12 + 1][10000 + 1];
    int helper(vector<int>& coins, int amount, int curr) {
        
        if (curr >= coins.size() || amount <= 0) {
            return (amount == 0) ? 0 : INT_MAX - 1;
        }

        if (dp[curr][amount] != -1) {
            return dp[curr][amount];
        }
        int res = -1;
        if (coins[curr] > amount) {
            int dont = 0 + helper(coins, amount - 0, curr + 1);
            res = dont;
            dp[curr][amount] = res;
        } else {
            int doo = 1 + helper(coins, amount - coins[curr], curr + 0);
            int dont = 0 + helper(coins, amount -0, curr + 1);
            res = min(doo, dont);
            dp[curr][amount] = res;
        }
        return dp[curr][amount]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = helper(coins, amount, 0);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};