#include <bits/stdc++.h>
#define f(i,q,a) for(long long i=q; i<a; i++)
#define ll long long
#define pb push_back
#define oo 666666666666666
#define MAXN 1000000
#define mod 10e9+7
char g[1002][1002];
char visited[1002][1002]={};
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
        ll n, m;
    cin>>n>>m;
    ll a, b;

    f(i,0,n+2)
    f(k,0,m+2)g[i][k]='#';

    vector<array<ll,2>>monsters={};

    f(i,1,n+1)
    f(k,1,m+1)
    {
    cin>>g[i][k];
    if(g[i][k]=='A')a=i,b=k;
    if(g[i][k]=='M')monsters.pb({i,k});
    }

    //BFS
    queue<array<ll,3>>q;
    f(i,0,monsters.size())g[monsters[i][0]][monsters[i][1]]='#', q.push({monsters[i][0],monsters[i][1],1});
    q.push({a,b,0});
    visited[a][b]='A';
    bool possible=false;
    while(!q.empty())
    {
    ll u=q.front()[0], v=q.front()[1], z=q.front()[2];
    if(z==0)
    {
    if(u==1||v==1||u==n||v==m)
    {
        a=u, b=v;
        possible=true;
        break;
    }
    if(!visited[u][v+1]&&g[u][v+1]!='#')visited[u][v+1]='R', q.push({{u,v+1,0}});
    if(!visited[u][v-1]&&g[u][v-1]!='#')visited[u][v-1]='L', q.push({{u,v-1,0}});
    if(!visited[u+1][v]&&g[u+1][v]!='#')visited[u+1][v]='D', q.push({{u+1,v,0}});
    if(!visited[u-1][v]&&g[u-1][v]!='#')visited[u-1][v]='U', q.push({{u-1,v,0}});
    }
    else
    {
    if(!visited[u][v+1]&&g[u][v+1]!='#')g[u][v+1]='#', q.push({{u,v+1,1}});
    if(!visited[u][v-1]&&g[u][v-1]!='#')g[u][v-1]='#', q.push({{u,v-1,1}});
    if(!visited[u+1][v]&&g[u+1][v]!='#')g[u+1][v]='#', q.push({{u+1,v,1}});
    if(!visited[u-1][v]&&g[u-1][v]!='#')g[u-1][v]='#', q.push({{u-1,v,1}});
    }
    q.pop();
    }
    if(possible)
    {
    string s;
    while(visited[a][b]!='A')
    {
        s+=visited[a][b];
        if(visited[a][b]=='L')b++;
        else if(visited[a][b]=='R')b--;
        else if(visited[a][b]=='U')a++;
        else if(visited[a][b]=='D')a--;
    }
    reverse(s.begin(),s.end());
    cout<<"YES"<<endl<<s.size()<<endl<<s<<endl;
    }
    else cout<<"NO"<<endl;
}
