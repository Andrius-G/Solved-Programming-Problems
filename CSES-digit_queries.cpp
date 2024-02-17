#include <bits/stdc++.h>
#define f(i,q,a) for(long long i=q; i<=a; i++)
#define ll long long
#define pb push_back
#define oo 666666666666666
#define MAXN 200000
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    ll q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        ll numbers=9, k=1;
        ll ans;
        for(ll digits=1; digits<=19; digits++)
        {
            if(n-(numbers*digits)>0)n-=(numbers*digits), numbers*=10,  k*=10;
            else
            {
                ll N=k+((n+digits-1)/digits)-1;
                ll rem=n%digits;
                if(rem==0)rem=digits;
                for(ll i=0; i<(digits-rem); i++)N/=10;
                ans=N%10;
                break;
            }
        }//O(10^2)
        cout<<ans<<endl;
    }
}
