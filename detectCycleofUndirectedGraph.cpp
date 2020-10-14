//tushar video
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

vector<int> graph[10000]; 
vector<int> rankpriority(10000,1); //didnt initialise with 0 because it will lead no incrementation in rank priority
vector<int> parent(10000);

void initialise_parent(){
    for(int i=0;i<parent.size();i++)
        parent[i]=i;
}

int find(int i){
    while(parent[i]!=i){
        parent[i]=parent[parent[i]];     //path compression for optimization 
        i=parent[i];
    }
    return i;
}

void union_(int x , int y){
    if(rankpriority[x]>rankpriority[y]){
        parent[y]=parent[x];
        rankpriority[x]=rankpriority[x]+rankpriority[y];
    }
    else{
        parent[x]=parent[y];
        rankpriority[y]=rankpriority[y]+rankpriority[x];
    }
}


bool detectcycle(int nodes){
    for(int i=0;i<nodes;i++){
        for(int j=0;j<graph[i].size();j++){
            int x=find(i);
            int y=find(graph[i][j]);

            if(x==y) return true;
            else{
                union_(x,y); 
            }
        }
    }
    return false;
}


signed main(){
    FAST
	int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        // graph[b].push_back(a);
    }

    initialise_parent();

    detectcycle(nodes) ? cout<<"Yes"<<endl :  cout<<"No"<<endl;
}