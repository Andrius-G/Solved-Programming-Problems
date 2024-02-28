//2024-02-28. Classic Bellman-Ford
#include <bits/stdc++.h>
#define f(i,q,a) for(long long i=q; i<=a; i++)
#define ll long long
#define pb push_back
#define oo 666666666666666
#define MAXN 1000000
#define mod 10e9+7
using namespace std;
struct edge
{
    ll a, b, weight;
};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    ll n, m;
    cin>>n>>m;
    vector<edge>g;
    if(n==1)
    {
        bool pos=0;
        f(i,1,m)
        {
            ll a, b, w;
            cin>>a>>b>>w;
            edge e;
            e.a=a;
            e.b=b;
            e.weight=w;
            if(w>0)
            {
                pos=1;
                break;
            }
            g.pb(e);
        }
        if(pos)cout<<-1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    f(i,1,m)
    {
        ll a, b, w;
        cin>>a>>b>>w;
        edge e;
        e.a=a;
        e.b=b;
        e.weight=w;
        g.pb(e);
    }
    //Bellman-Ford
    ll d[n+1]={};
    d[1]=0;
    f(i,2,n)d[i]=-oo;
    f(i,1,n-1)
    {
        for(edge e: g)
        {
            if(d[e.a]>-oo)
            {
                d[e.b]=max(d[e.b],d[e.a]+e.weight);
            }
        }
    }
    f(i,1,n-1)
    {
    for(edge e: g)
        {
            if(d[e.a]>-oo)
            {
                if(d[e.b]<d[e.a]+e.weight)d[e.b]=oo;
            }
        }
    }
    if(d[n]==oo)cout<<-1<<endl;
    else cout<<d[n]<<endl;
    return 0;
}
