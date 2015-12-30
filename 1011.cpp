#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[25][25],dp[20][100000],z,t,ans;
ll ff(ll ps,ll mask)
{
    if(ps>=n)
        return 0;
    if(dp[ps][mask]!=-1)
        return dp[ps][mask];
    for(ll i=0;i<n;i++)
    {
        if(!(mask&(1LL<<i)))
            dp[ps][mask]=max(dp[ps][mask],a[ps][i]+ff(ps+1,mask|(1LL<<i)));
    }
    return dp[ps][mask];
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++)
            cin>>a[i][j];
        memset(dp,-1,sizeof(dp));
        ans=ff(0,0);
        cout<<"Case "<<++z<<": "<<ans<<endl;
    }
}
