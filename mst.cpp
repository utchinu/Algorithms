#include<bits/stdc++.h>
using namespace std;
#define fi                  first
#define se                  second
#define pb push_back
typedef long ll;
typedef pair<ll,ll> pi;

ll prims(vector<pair<ll,ll>> v[n+1],ll n)
{
    priority_queue<pi,vector<pi>,greater<pi>> p;
    ll s=0,visited[n+1]={0};

    p.push(make_pair(0,1));
    while(!p.empty())
    {
        pair<ll,ll> q=p.top();
        ll a=q.se;
        visited[a]=1;
        for(auto i=a.begin();i!=a.end();i++)
        {
            if(!visited[i.se])
            {
                p.push()
            }
        }
    }


}


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll p,n,m;
        cin>>p>>n>>m;
        vector<pair<ll,ll>> v[n+1];
        for(ll i=0;i<m;i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            v[a].pb(make_pair(b,c));
            v[b].pb(make_pair(a,c));
        }
        ll a=prims(v,n);

    }

