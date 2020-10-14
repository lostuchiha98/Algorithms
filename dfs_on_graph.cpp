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

vector<int> Graph[10000];
vector<int> visits(10000,false);

void dfs(int firstNode){

    stack<int> st;
    st.push(firstNode);
    

    while (!st.empty())
    {
        int nextnode=st.top();
        cout<<st.top()<<" ";
        visits[st.top()]=true;
        st.pop();

        for(int i=0;i<Graph[nextnode].size();i++){
            if(!visits[Graph[nextnode][i]]){
                st.push(Graph[nextnode][i]);
                visits[Graph[nextnode][i]]=true;
            }
        }
    }
    
}

void dfs_r(int start){
    
        cout<<start<<" ";
        visits[start]=true;
    
    for(int i=0;i<Graph[start].size();i++){
        if(!visits[Graph[start][i]])
            dfs(Graph[start][i]);
    }
}
 


signed main(){
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    int startNode;
    cin>>startNode;


    // dfs(startNode);
    

    dfs_r(startNode);

    //Note : both two function cannot be executed at the same time
    //because vector is assigned globally and stack version of dfs
    //will mark the nodes visited as it is called first result there
    // will be only one execution the function which is called first


}