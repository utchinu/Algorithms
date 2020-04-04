#include<bits/stdc++.h>
using namespace std;

int mac(int a,int b)
{
    if(a%b==0)
    return(b);
    else
    {
        return(mac(b,a%b));
    }
    
}