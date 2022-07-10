#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,INT_MIN);
        priority_queue<pair<int,int>> pq;
        dp[n-1] = nums[n-1];
        pq.push({nums[n-1],n-1});
        
        for(int i = n-2; i>=0; i--){
            // pop until the index is in range from current pos ie i
            while(!pq.empty() && pq.top().second - i > k){
                pq.pop();
            }
            dp[i] = nums[i] + pq.top().first;
            pq.push({nums[i] + pq.top().first, i});
        }
        return dp[0];
    }
};


int main(){
    vector<int> v = {1,-1,-2,4,-7,3};
    int k = 2;
    
    cout << Solution().maxResult(v, k) << endl;
}