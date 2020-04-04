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

vector<vector<ll>> h;
vector<deque<ll>> dq;

void insert(deque<ll> &d,ll v){
    while((!d.empty())&&(d.back()>v)){
        d.pop_back();
    }
    d.push_back(v);
}

void del(deque<ll> &d,ll v){
    if((!d.empty())&&(d.front()==v))
    d.pop_front();
}

int main()
{
    ll n,m,a,b,g,x,y,z,ans=0;
    cin>>n>>m>>a>>b>>g>>x>>y>>z;
    h.resize(n);
    for(ll i=0;i<n;i++){
        h[i].resize(m);
        for(ll j=0;j<m;j++){
            h[i][j]=g;
            g=((g*x)%z+y)%z;
        }
    }

    dq.resize(m);
    for(ll j=0;j<m;j++){
        for(ll i=0;i<a;i++)
        insert(dq[j],h[i][j]);
    }
    deque<ll> dqq1;
    for(ll i=0;i<b;i++)
    insert(dqq1,dq[i].front());

    ans+=dqq1.front();
    for(ll i=b;i<m;i++){
        del(dqq1,dq[i-b].front());
        insert(dqq1,dq[i].front());
        ans+=dqq1.front();
    }


    for(ll i=1;i<=(n-a);i++){
        deque<ll> dqq;
        for(ll j=0;j<m;j++) { 
            del(dq[j],h[i-1][j]);
            insert(dq[j],h[i+(a-1)][j]);
       }
       for(ll j=0;j<b;j++)
       insert(dqq,dq[j].front());
       ans+=dqq.front();

       for(ll j=b;j<m;j++){
           del(dqq,dq[j-b].front());
           insert(dqq,dq[j].front());
           ans+=dqq.front();
       }
    }
    cout<<ans;
}