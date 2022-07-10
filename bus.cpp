#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& pass, int capacity) {
        sort(buses.begin(), buses.end());
        sort(pass.begin(), pass.end());
        
        int last = -1;
        int ans = -1;
        int n = buses.size();
        for(int i = 0; i<n; i++){
            int c = capacity;
            int depart = buses[i];
            stack<int> st;
            for(int j = last+1; j<pass.size() && c>0 && pass[j] <=depart; j++){
                st.push(j);
                last = j;
                c--;
            }
            
            if(c == 0){
                int p = -1;
                while(st.size() > 1){
                    int t = st.top();
                    st.pop();
                    int t1 = st.top();
                    if(pass[t]-pass[t1] > 1){
                        p = pass[t]-1;
                        break;
                    }
                }
                if(p != -1){
                    ans = p;
                }
                else{
                    if(i == 0){
                        ans = pass[st.top()]-1;
                    }
                    else{
                        if(buses[i-1] < pass[st.top()]-1)
                            ans = pass[st.top()]-1;
                    }
                }
            }
            else{

int p = -1;
                while(st.size() > 1){
                    int t = st.top();
                    st.pop();
                    int t1 = st.top();
                    if(pass[t]-pass[t1] > 1){
                        p = pass[t]-1;
                        break;
                    }
                }
                if(p != -1){
                    ans = p;
                }
                else{
                    if(i == 0){
                        ans = pass[st.top()]-1;
                    }
                    else{
                        if(buses[i-1] < pass[st.top()]-1)
                            ans = pass[st.top()]-1;
                    }
                }

                // ans = depart;
            }
        }
        return ans;
    }
};


int main(){
    // vector<int> b = {10,20,30};
    // vector<int> p = {19,13,26,4,25,11,21};
    
    // vector<int> b = {10,12};
    // vector<int> p = {9,10,11,12};
    
    vector<int> b = {2};
    vector<int> p = {2};

    int t = 2;
    Solution().latestTimeCatchTheBus(b,p,t);
}