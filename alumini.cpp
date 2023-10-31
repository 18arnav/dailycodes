#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void dfs(int node,vector<int> adj[],vector<bool> &visited,int &count){
    visited[node]=true;
    count++;
    ans.push_back(node);
    for(int i:adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited,count);
        }
    }
}
vector<int> idsofalumini(vector<int> aluminiid){
    vector<int> adj[aluminiid.size()+1];
    int n=aluminiid.size();
    for(int i=0;i<n;i++){
        int u=i+1;
        int v=aluminiid[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1,false);
    int maxi=0;
    vector<int> maxinode;
    for (int i = 1; i <=n; i++)
    {
        int count=0;
        if(!visited[i]){
            dfs(i,adj,visited,count);
            if(count>maxi){
                maxi=count;
                // maxinode=i;
                maxinode.clear();
                maxinode.push_back(i);
            }else if(count==maxi){
                maxinode.push_back(i);
            }
        }
    }
    ans.clear();
    visited.clear();
    visited.resize(n+1,false);
    for (int i = 0; i < maxinode.size(); i++)
    {
    dfs(maxinode[i],adj,visited,maxi);
        
    }
    sort(ans.begin(),ans.end());
    return ans;
    
    

}
int main(){

    int alumini_size;
    cin>>alumini_size;
    vector<int> alumuiniid(alumini_size);
    for(int i=0;i<alumini_size;i++){
        cin>>alumuiniid[i];
    }
    vector<int> ans=idsofalumini(alumuiniid);
    for(auto i:ans){
        cout<<i<<" ";
    }


    return 0;
}