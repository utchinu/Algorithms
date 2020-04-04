//***Faithless is he that says farewell when the road darkens***

#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define ford(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)
#define fora(it,x) for(auto it:x)
#define PI 3.14159265
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef long double ld;
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

vector<ll> g[2*100001];
ll dp[2*100001];
ll sz[2*100001];
ll ans;

void calc(ll v,ll p){
    sz[v]=1;
    for(auto x:g[v]){
        if(x==p) continue;
        calc(x,v);
        dp[v]+=dp[x];
        sz[v]+=sz[x];
    }
    dp[v]+=sz[v];
}

void dfs(ll v,ll p){
    ans=max(ans,dp[v]);
    
    for(auto x:g[v]){
        if(x==p) continue;
        dp[v]=dp[v]-dp[x]-sz[x];
        sz[v]-=sz[x];
        dp[x]=dp[x]+dp[v]+sz[v];
        sz[x]=sz[x]+sz[v];

        dfs(x,v);

        dp[x]=dp[x]-dp[v]-sz[v];
        sz[x]=sz[x]-sz[v];
        dp[v]=dp[v]+dp[x]+sz[x];
        sz[v]=sz[v]+sz[x];
    }
}

int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<(n-1);i++){
        ll u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    calc(1,-1);
    dfs(1,-1);
    cout<<ans;
}