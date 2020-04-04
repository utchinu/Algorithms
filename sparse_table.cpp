//F(x,y)=x+y

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=100000;
const int k=5;

ll table[N][k];
ll a[N];

int main()
{
    ll n=16;
    
    for(ll i=0;i<n;i++)
    a[i]=i;

    //If the length of the query is '1'
    for(ll i=0;i<n;i++)
    table[i][0]=a[i];

    //Building table
    for(ll j=1;j<k;j++)
        for(ll i=0;i<=(n-(1<<j));i++){
            table[i][j]=table[i][j-1]+table[i+(1<<(j-1))][j-1];
        }

    ll q;
    cin>>q;

    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        
        ll ans=0;
        
        for(ll i=k-1;i>=0;i--)
        {
            if((1<<i)<=(r-l+1)){
             ans=ans+table[l][i]; 
             l+=(1<<i);
            }
        }
        cout<<ans<<"\n";
    }
}
