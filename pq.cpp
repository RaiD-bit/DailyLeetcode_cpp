#include<bits/stdc++.h>
using namespace std;


int main(){
    priority_queue<pair<int,int>> pq;
    pq.push({100,1});
    pq.push({200,3});
    pq.push({300,2});

    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
}
