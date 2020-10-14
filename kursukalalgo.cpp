#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int>>> graph;
vector<int>parent(10000),rankpriority(10000,1);


int find(int i){

    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

void union_(int x,int y){
    if(rankpriority[x]>rankpriority[y]){
        parent[y]=parent[x];
        rankpriority[x]=rankpriority[x] + rankpriority[y];
    }
    else{
        parent[x]=parent[y];
        rankpriority[x]=rankpriority[y]+rankpriority[x];
    }
}

void kruskalMST(int nodes){

    for(int i=0;i<nodes;i++) parent[i]=i;

    int minMST=0;
    for(int i=0;i<graph.size();i++){
        
        int x=find(graph[i].second.first);
        int y=find(graph[i].second.second);

        if(x!=y){
            minMST=graph[i].first + minMST;
            union_(x,y);
        }
        
    }
    cout<<minMST<<endl;

}


int main(){
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int src,des,cost;
        cin>>src>>des>>cost;
        graph.push_back({cost,{src,des}});
    }

    sort(graph.begin(),graph.end());
    kruskalMST(nodes);

}