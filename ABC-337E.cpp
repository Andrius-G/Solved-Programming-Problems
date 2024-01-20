//AtCoder Beginner Contest 337/E: A Classic D&C Problem
//Solved 2024-01-20
#include <bits/stdc++.h>
#define f(i,q,a) for(long long i=q; i<=a; i++)
#define ll long long
#define pb push_back
#define oo 666666666666666
#define MAXN 200001
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin>>n;
    ll M=ceil(log2(n));
    ll sizes[M+1]={};
    f(i,1,M)sizes[i]=1<<(M-i);
    bool drinks[n+1][M+1]={};
    cout<<M<<endl;
    f(p,1,M)
    {
    ll sum=0;
    vector<ll>things={};
    f(d,1,n)
    {
        if(((d-1)/sizes[p])%2==0)drinks[d][p]=1, sum++, things.pb(d);
        else drinks[d][p]=0;
        //cout<<drinks[d][p]<<" ";
    }
    //cout<<endl;

    cout<<sum<<" ";
    if(sum>1)f(i,0,sum-2)cout<<things[i]<<" ";
    cout<<things[sum-1]<<endl;

    }
    string res;
    cin>>res;
    res="#"+res;

    ll L=1, R=1<<M, m=1<<(M-1);
    f(i,1,M)
    {
        //cout<<L<<" "<<R<<endl;
        if(res[i]=='1')
        {
            R=m;
        }
        else
        {
            L=m+1;
        }
        m=(L+R)/2;
    }
    cout<<L<<endl;
    return 0;
}
