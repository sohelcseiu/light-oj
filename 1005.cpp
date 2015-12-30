#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k,t,n,z,ans,i,d;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        ll kk=min(k,n-k),d=1,ans=1;
        if(k>n){
            printf("Case %lld: 0\n",++z);
            continue;}
        for(i=0;i<kk;i++)
            ans*=(n-i);
            for(i=1;i<=kk;i++)
                d*=i;
            ans/=d;
            ans*=ans;

        for(i=1;i<=k;i++)
            ans*=i;
            printf("Case %lld: %lld\n",++z,ans);
    }
}
