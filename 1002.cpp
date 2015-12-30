#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll t,m,n,x,y,z,ds,dis[505],zz;
struct dd
{
    ll v,w;
};
vector<dd>v[505];
dd d;
void dfs(ll u,ll dd)
{
    dis[u]=dd;
    for(ll i=0;i<v[u].size();i++)
    {
        ll vv=v[u][i].v;
        ll dst=max(dd,v[u][i].w);
        if(dis[vv]==-1||dis[vv]>dst)
        {
            dfs(vv,max(dd,dst));
        }
    }
}
int main()
{
    ll i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%lld%lld%lld",&x,&y,&z);
            d.w=z;
            d.v=y;
            v[x].pb(d);
            d.v=x;
            v[y].pb(d);
        }
        scanf("%lld",&ds);
        memset(dis,-1,sizeof(dis));
        dfs(ds,0);
        printf("Case %lld:\n",++zz);
        for(i=0;i<n;i++)
        {
            if(dis[i]==-1)
                printf("Impossible\n");
            else
                printf("%lld\n",dis[i]);
        }
        for(i=0;i<n;i++)
            v[i].clear();

    }
}
