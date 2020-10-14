#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[10000];

void primsMST(int start){
    int ans=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> vists(10000,false);
    pq.push(make_pair(0,start));
    while (!pq.empty()){
        int u=pq.top().second;
        if(!vists[u])
            ans=ans+pq.top().first;
        vists[u]=true;
        pq.pop();
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i].first;
            int cost=graph[u][i].second;
            if(!vists[v]){
                pq.push(make_pair(cost,v));
            }
        }
    }
    cout<<ans<<endl;   
}

int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        int src,dest,cost;
        cin>>src>>dest>>cost;
        graph[src].push_back(make_pair(dest,cost));
        graph[dest].push_back(make_pair(src,cost));

    }
    int start;
    cin>>start;
    primsMST(start);
}