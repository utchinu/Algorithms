//***Little by little one travels far***
 
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

class trie_node
{
    public:
    trie_node *child[26];
    int cnt;
    trie_node();
};

trie_node::trie_node(){
    cnt=0;
    forn(i,26) child[i]=NULL;
}

void insert(trie_node *root,string s){
    trie_node *te=root;
    for(ll i=0;i<s.length();i++){
        if(!(te->child[s[i]-'a'])){
            trie_node *temp=new trie_node();
            te->child[s[i]-'a']=temp;
        }
        te=te->child[s[i]-'a'];
    }
    (te->cnt)++;
}

/*ll dfs(trie_node *root,ll lp){
    ll ans=0,c=root->cnt;
    for(ll i=0;i<26;i++){
        if(!(root->child[i])) continue;
        //cout<<(char)(i+'a');
        //cout<<c<<" ";
        ans+=dfs(root->child[i],lp+1);
        c+=((root->child[i])->cnt);
    }

    while(c>=2){
        c-=2;
        ans+=((lp/2)*(lp/2));
    }
    root->cnt=c;
  //  cout<<ans<<" ";
    return(ans);
}

int main()
{
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        trie_node *root=new trie_node();
        forn(i,n){
            string s,v;
            cin>>s;
            forn(j,s.length()){
                v.pb(s[j]);
                v.pb(s[s.length()-1-j]);
            }
            insert(root,v);
        }
        cout<<dfs(root,(ll)0)<<"\n";
    }
}*/