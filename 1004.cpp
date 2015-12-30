#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,i,j,k,d,a[201][201],dp[201][201],ts;
ll ban(ll u, ll v)
{
    if(u>2*n-1||v<1||v>2*n-1)
        return 0;
    if(dp[u][v]!=-1)
        return dp[u][v];
    return dp[u][v]=a[u][v]+max(ban(u+1,v-1),ban(u+1,v+1));
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(dp,-1,sizeof(dp));
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            for(j=n-i+1;j<=n+i-1;j+=2)
                scanf("%lld",&a[i][j]);
        k=1;
        for(;i<=2*n-1;i++)
        {
            k++;
            for(j=k;j<=2*n-k+1;j+=2)
              scanf("%lld",&a[i][j]);
        }
        d=ban(1,n);
        printf("Case %lld: %lld\n",++ts,d);
    }
}
