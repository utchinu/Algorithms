#include<bits/stdc++.h>

using namespace std;

void addEdge(list<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(list<int> adj[],int v,int s)
{
    queue<int> q;
    int a[v]={0};
    q.push(s);
    
    while(!q.empty())
    {
        int te=q.front();
        q.pop();
        cout<<te<<" ";
        a[te-1]=1;
        for(auto i=adj[te].begin();i!=adj[te].end();i++)
        {
            if(a[*i-1]==0)
            q.push(*i);
        }
    }
    
}

void dfs(list<int> adj[],int v,int s)
{
    stack<int> q;
    int a[v]={0};
    q.push(s);
    while(!q.empty())
    {
        int te=q.top();
        cout<<te<<" ";
        q.pop();
        a[te-1]=1;
        for(auto i=adj[te].begin();i!=adj[te].end();i++)
        {
            if(a[*i-1]==0)
            q.push(*i);
        }
    }
    
}

int main()
{
    int v;
    cin>>v;
    list<int> adj[v];
    
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 2, 4); 
    addEdge(adj, 2, 5); 
    addEdge(adj, 3, 6); 
    addEdge(adj, 3, 7); 
    dfs(adj,v,1);
}