#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int>graph[100001];
vector<bool>visited(100001);
vector<int>dist(100001);
void dfs(int v){
    cout<<v<<" ";
  visited[v]=true;
  for(int x:graph[v]){
    if(visited[x]==false){
        dfs(x);
    }
  }
}
void bfs(int v){
queue<int>q;
q.push(v);
visited[v]=true;
dist[v]=0;
while(!q.empty()){
    int f=q.front();
    q.pop();
    cout<<f<<" ";
    for(int x:graph[f]){
        if(visited[x]==false){
            visited[x]=true;
            q.push(x);
            dist[x]=1 + dist[f];
        }
    }
}
}
int main(){
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++){
    visited[i]=false;
 }
 for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
 }
 for(int i=1;i<=n;i++){
    dist[i]=0;
 }
 cout<<"Depth"<<endl;
 dfs(1);
 cout<<endl;
 cout<<"Breadth"<<endl;
 bfs(1);
 cout<<endl;
 cout<<"Distance"<<endl;

 for(int i=1;i<=n;i++){
     cout<<dist[i]<<" ";
 }
 cout<<endl;
}
