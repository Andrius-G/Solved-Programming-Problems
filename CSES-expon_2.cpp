#include <bits/stdc++.h>
#define f(i,q,a) for(long long i=q; i<=a; i++)
#define ll long long
#define pb push_back
#define oo 666666666666666
#define MAXN 1000000
using namespace std;
const ll mod = 1e9+7;
ll mod_exp_1(ll b, ll c)
{
    if(b==0&&c==0)return 1;
    if(b==0)return 0;
    if(c==0)return 1;
    if(c%2==0)return (mod_exp_1(b,c/2)*mod_exp_1(b,c/2))%(mod-1);
    return (b*(mod_exp_1(b,c/2)*mod_exp_1(b,c/2)%(mod-1)))%(mod-1);
}
ll mod_exp_2(ll a, ll b)
{
    if(a==0&&b==0)return 1;
    if(a==0)return 0;
    if(b==0)return 1;
    if(b%2==0)return (mod_exp_2(a,b/2)*mod_exp_2(a,b/2))%(mod);
    return (a*(mod_exp_2(a,b/2)*mod_exp_2(a,b/2)%mod))%(mod);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    ll q;
    cin>>q;
    while(q--)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        cout<<mod_exp_2(a,mod_exp_1(b,c))<<"\n";
    }
    return 0;
}
