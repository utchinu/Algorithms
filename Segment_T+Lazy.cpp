#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define forn(i,n) for(auto i=0; i<(n); i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define mk make_pair
#define fi                  first
#define se                  second
#define pii                 pair<int,int>
#define all(c)              c.begin(),c.end()
#define sz(c)               (int)c.size()
#define N 100000
ll a[N];
ll lazy[4*N];
ll tree[4*N]; //Tree nodes are starting from 0


void recalculate(ll node)
{
   tree[node]=(tree[2*node+1]+tree[2*node+2]);  //(1)
}

void build(ll node,ll left,ll right)
{
    if(left==right)
    tree[node]=a[right];
    else
    {
        int middle =(left+right)/2;
        build(2*node+1,left,middle);
        build(2*node+2,middle+1,right);
        recalculate(node);
    }
}

void update(ll node,ll l,ll r,ll i,ll j,ll val) //Update the range from [i,j] with value val
{
    if(lazy[node]!=0)  //Dealing with the pending update and propagating it to its children
    {   
        tree[node]+=lazy[node];
        if(l!=r){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }  

    if((i>r)||(j<l)||(i>j))  //If current segment is not in the range [i,j]
        return ;

    if((i<=l)&&(j>=r))  //if [l,r] lies between [i,j]  (lazy propagation)
    {
        tree[node]+=val;
        if(l!=r){
            lazy[2*node+1]+=val;
            lazy[2*node+2]+=val;
        }
        return;
    }

    ll m=(l+r)/2;
    update(2*node+1,l,m,i,j,val);
    update(2*node+2,m+1,r,i,j,val);

    recalculate(node);
}

ll query(ll node,ll l,ll r,ll i,ll j) //Query for the range [i,j]
{
    if(lazy[node]!=0){ //Pending update
        tree[node]+=lazy[node];
        if(l!=r){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if((r<i)||(l>j))   //(2)
        return 0;

    if((l>=i)&&(r<=j)){
        return (tree[node]);
    }

    ll m=(l+r)/2;
    ll q1=query(2*node+1,l,m,i,j);
    ll q2=query(2*node+2,m+1,r,i,j);
    return((q1+q2));      //(3)
}
 
int main()
{
    ll n=100;
    for(ll i=0;i<=100;i++)
        a[i]=1;
    build(0,0,n-1);
   // cout<<tree[0]<<" ";
    ll q=query(0,0,n-1,2,6);
    cout<<q;
}