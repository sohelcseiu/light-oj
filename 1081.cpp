#include<bits/stdc++.h>
using namespace std;
#define ll long
#define pb push_back
ll n,q,t,a[505][505],table[12][505][505],x,y,z,md,zz;
void init(ll u)
{
    for(ll i=1;i<=n;i++)
        table[0][u][i]=a[u][i];

        for(ll i=1;(1<<i)<=n;i++)
        {
            for(ll j=1;j+(1<<i)-1<=n;j++)
                table[i][u][j]=max(table[i-1][u][j],table[i-1][u][j+(1<<i-1)]);
        }
}
ll read(ll u,ll i,ll j)
{
    ll k=log2(j-i);
    return max(table[k][u][i],table[k][u][j-(1<<k)+1]);
}
int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld",&n,&q);
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
            scanf("%ld",&a[i][j]);
        for(ll i=1;i<=n;i++)
            init(i);
        printf("Case %ld:\n",++zz);
        while(q--)
        {
            scanf("%ld%ld%ld",&x,&y,&z);
            ll i=x+z-1,j=y+z-1;
            md=0;
            for(ll q=x;q<=i;q++)
            md=max(md,read(q,y,j));
            printf("%ld\n",md);
        }
        memset(table,0,sizeof(table));
    }
}
