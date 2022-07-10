class Solution {
public:
    /*
        this approach has a complexit of n*k ~ 10^10 in this case.
        so this doesn't pass.
        sadly
    */
    int fun(vector<int> &nums, int pos, int k, vector<int> &dp){
        // cout << pos << " ";
        if(pos == nums.size()-1){
            return nums[pos];
        }
        if(pos >= nums.size()){
            return INT_MIN;
        }
        if(dp[pos] != INT_MIN){
            return dp[pos];
        }
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = pos+1; i<= min(n-1, pos+k);i++){
            if(nums[pos] < 0)
                ans = max(ans,nums[pos] + max(INT_MIN-nums[pos],fun(nums, i, k,dp)));
            else
                ans = max(ans,nums[pos] + fun(nums, i, k,dp));
        }
        
        return dp[pos] = ans;
    }
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MIN);
        
        return fun(nums, 0, k,dp);
    }
};
