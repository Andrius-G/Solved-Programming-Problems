#include <bits/stdc++.h>
#define f(i,q,a) for(long long i=q; i<=a; i++)
#define ll long long
#define pb push_back
#define oo 666666666666666
#define MAXN 1000000
using namespace std;
ll solve(ll a, ll b)
{
    if(a==1&&b==1)return 0;
    if(a==1||b==1)return abs(b-a);
    if(a<b)swap(a,b);
    ll K=a/b;
    return K+solve(a-(K*b),b);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    ll M=oo;
    f(i,1,MAXN)
    {
        if(__gcd(n,i)==1)M=min(M,solve(n,i));
    }
    cout<<M<<endl;
    return 0;
}
