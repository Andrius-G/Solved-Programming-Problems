//AtCoder Beginner Contest 335/E: Equivalence Relations on DAG
//Solved 2024-01-12
#include <bits/stdc++.h>
#define f(i,q,a) for(long long i=q; i<a; i++)
#define ll long long
#define pb push_back
#define oo 666666666666666
#define MAXN 200001
using namespace std;
set<ll>g[MAXN]={};
bool _ignore[MAXN]={};
struct dsu
{
    ll n;
    ll* p;
    ll* sz;
    dsu(int N) : n(N) {
        p=new ll[n+1];
        sz=new ll[n+1];
        f(i,0,n+1)p[i]=i, sz[i]=1;
    }
    ll find(ll u)
    {
        return p[u]==u ? u : p[u]=find(p[u]);
    }
    void unite(ll u, ll v)
    {
        u=find(u);
        v=find(v);
        if(sz[u]>=sz[v])
        {
            p[v]=u, sz[u]+=v, find(v);
            auto V=g[v];
            g[v].clear();
            for(auto vv: V)g[u].insert(find(vv));
            _ignore[v]=1;
        }
        else
        {
            p[u]=v, sz[v]+=u, find(u);
            auto U=g[u];
            g[u].clear();
            for(auto uu: U)g[v].insert(find(uu));
            _ignore[u]=1;
        }
        return;
    }
};
int main()
{
    std::ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll n, m;
    cin>>n>>m;
    ll a[n+1]={};
    f(i,1,n+1)cin>>a[i];
    dsu d(n);
    f(i,0,m)
    {
        ll u, v;
        cin>>u>>v;
        u=d.find(u);
        v=d.find(v);
        if(u!=v)
        {
            if(a[u]<a[v])g[u].insert(v);
            else if(a[u]>a[v])g[v].insert(u);
            else d.unite(u,v);
        }
    }
    vector<array<ll,2>>C={};
    f(i,1,n+1)if(!_ignore[i])C.pb({a[i],i});
    sort(C.begin(),C.end());
    ll nn=C.size();
    ll chips[n+1]={};
    bool yes=0;
    f(i,0,C.size())
    {
        if(d.find(C[i][1])==d.find(1))yes=1, chips[d.find(C[i][1])]=1;
        if(yes)
        {
        for(auto u: g[d.find(C[i][1])])
        {
            if(chips[d.find(C[i][1])]>0)chips[d.find(u)]=max(chips[d.find(u)],chips[d.find(C[i][1])]+1);
        }
        }
    }
    cout<<chips[d.find(n)]<<endl;
    return 0;
}
