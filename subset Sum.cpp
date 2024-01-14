bool isSubsetSum(vector<int> arr, int sum){
    int n = arr.size();
    vector<vector<bool>> mem(n + 1, vector<bool>(sum + 1, false));
    // Initialization for base cases

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(arr[i - 1] > j) {
                mem[i][j] = mem[i - 1][j];
            }
            else if(arr[i - 1] <= j) {
                mem[i][j] = mem[i - 1][j - arr[i - 1]] || mem[i - 1][j];
            }
        }
    }
    return mem[n][sum];
}
