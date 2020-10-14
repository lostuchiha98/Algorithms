#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#define int        long long
#define max(a,b)    (a>b?a:b)
#define min(a,b)    (a<b?a:b)
#define endl        '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

vector<pair<int,int>> graph[10000];

void dijkstra(int start,int cost,int nodes){

    vector<int> dist(nodes,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(cost,start));
    dist[pq.top().second]=0;

    while (!pq.empty()){
           
        int u=pq.top().second;
        pq.pop();
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i].first;
            int weight=graph[u][i].second;

            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }

    }
    
    for(int i=0;i<dist.size();i++){
        cout<<"Distance from node "<<start<<" "<<dist[i]<<endl;
    }

}


signed main(){
    FAST
	int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        int a,b,cost;
        cin>>a>>b>>cost;
        graph[a].push_back(make_pair(b,cost));
        graph[b].push_back(make_pair(a,cost));
    }

    int startPoint;
    cin>>startPoint;

    for(int i=0;i<nodes;i++){
        if(i==startPoint)
            dijkstra(i,0,nodes);
    }

}