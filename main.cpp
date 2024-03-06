#include <bits/stdc++.h>
#define f(i,q,a) for(long long i=q; i<=a; i++)
#define ll long long
#define pb push_back
#define oo 666666666666666
#define MAXN 1000000
using namespace std;
vector<pair<ll,bool>>pos[1000001]={};
unordered_map<ll,ll>mp={};
string dots[22]={};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    ll a[1001]={};
    ll h=0, minh=0;
    ll k=1;
    f(i,1,n)cin>>a[i], h+=(k*(a[i]-1)), a[i]=h, k=-k, minh=min(minh,h);
    if(minh<0)
    {
        minh=-minh;
        f(i,1,n)a[i]+=minh;
    }
    h=minh;
    ll pt=0;
    f(i,1,n)
    {
        //cout<<i<<endl;
        if(i%2==1)
        {
            f(j,h,a[i])
            {
                pos[j].pb({pt,1});
                mp[j]=0;
                pt++;
            }
        }
        else
        {
            for(ll j=h; j>=a[i]; j--)
            {
                //cout<<j<<" ";
                pos[j].pb({pt,0});
                mp[j]=0;
                pt++;
            }
        }
        h=a[i];
    }
    string s=".";
    f(i,0,21)
    {
        dots[i]=s;
        s=s+s;
    }
    ll maxH=0;
    f(i,1,n)
    {
        maxH=max(maxH,a[i]);
    }
    for(ll row=maxH; row>=0; row--)
    {
        ll xprev=0;
        while(mp[row]<pos[row].size())
        {
        auto pp=pos[row][mp[row]];
        mp[row]++;
        bool d=pp.second;
        ll x=pp.first;
        ll X=x-xprev;
        for(ll pw2=21; pw2>=0; pw2--)
        {
            if(dots[pw2].size()<=X)
            {
                cout<<dots[pw2];
                X-=dots[pw2].size();
            }
        }
        if(d)cout<<"/";
        else cout<<"\\";
        xprev=x+1;
        }
        ll X=pt-xprev;
        for(ll pw2=21; pw2>=0; pw2--)
        {
            if(dots[pw2].size()<=X)
            {
                cout<<dots[pw2];
                X-=dots[pw2].size();
            }
        }
        cout<<"\n";
    }
    return 0;
}
