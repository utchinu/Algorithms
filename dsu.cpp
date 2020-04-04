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

ll par[2001],h[2001],b[4001];

ll find(ll u){
    return((par[u]==u)? u:(par[u]=find(par[u])));
}

void union1(ll u,ll v){
    ll a=find(u);
    ll c=find(v);
    if(a==c) return ;
    if(h[a]<h[c]) swap(a,c);
    par[c]=a;
    h[a]+=(h[a]==h[c]);
    return ;
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,ans=1,mod=1000000007;
        cin>>n;
        for1(i,n){ 
            par[i]=i;
            h[i]=0;
        }
        for1(i,2*n) b[i]=0;
        ll m;
        cin>>m;
        while(m--){
            ll l,r;
            cin>>l>>r;
            b[l+r]=max(b[l+r],r-l);
        }

        for(ll i=2;i<=2*n;i++){
            if(b[i]==0) continue;
            ll l=(i-b[i])/2;
            ll r=(i+b[i])/2;
            while(l<r){
                union1(l,r);
                l++;
                r--;
            }
        }
        for(ll i=1;i<=n;i++){
            if(par[i]==i)
                ans=(ans*26)%mod;
        }
        cout<<ans<<"\n";
    }
}