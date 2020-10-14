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
vector<bool> visits(10000,false);
 
void bfs(int firstnode){
    queue<int> que;
    que.push(firstnode);
    visits[firstnode]=true;

    while (!que.empty())
    {   
        int nextnode=que.front();
        cout<<que.front()<<" ";
        que.pop();

        for(int i=0;i<graph[nextnode].size();i++){
            if(!visits[graph[nextnode][i]]){
                que.push(graph[nextnode][i]);
                visits[graph[nextnode][i]]=true;
            }

        }
        
    }   

}


signed main(){

	int nodes,edges;
    cin>>nodes>>edges;    



    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    
    int startPoint;
    cin>>startPoint;
    
    bfs(startPoint);
    
}