#include <bits/stdc++.h>
#define f(i,q,a) for(long long i=q; i<=a; i++)
#define ll long long
#define pb push_back
#define oo 666666666666666
#define MAXN 1000000
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    ll a[n+1]={}, b[n+1]={};
    f(i,1,n)cin>>a[i], b[a[i]]=i;
    ll sum=1;
    f(i,2,n)
    {
        if(b[i]<b[i-1])sum++;
    }
    cout<<sum<<"\n";
    return 0;
}
