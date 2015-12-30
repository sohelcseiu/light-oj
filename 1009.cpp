#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll t,n,r,x,y,st,dst,dis[105],z,diss[105];
vector<ll>g[105];
void dfs(ll u,ll d)
{
    dis[u]=d;
    for(ll i=0;i<g[u].size();i++)
    {
        ll v=g[u][i];
        if(dis[v]==-1||dis[v]>(d+1))
            dfs(v,d+1);
    }
}
ll bfs()
{
    queue<ll>q;
    ll mx=0;
    for(ll i=0;i<n;i++)
    {
        memset(diss,-1,sizeof(diss));
        diss[i]=dis[i];
        q.push(i);
        while(!q.empty())
        {
            ll u=q.front();
            q.pop();
            for(ll j=0;j<g[u].size();j++)
            {
                ll v=g[u][j];
                if(diss[v]==-1)
                {
                    diss[v]=diss[u]+1;
                    q.push(v);
                }
            }
        }
        mx=max(mx,diss[dst]);
    }
    return mx;
}
int main()
{
    ll i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&r);
        for(i=0;i<r;i++)
        {
            scanf("%lld%lld",&x,&y);
            g[x].pb(y);
            g[y].pb(x);
        }
        scanf("%lld%lld",&st,&dst);
        memset(dis,-1,sizeof(dis));
        dfs(st,0);
        bfs();
        printf("Case %lld: %lld\n",++z,bfs());
        for(i=0;i<n;i++)
            g[i].clear();
    }
}
