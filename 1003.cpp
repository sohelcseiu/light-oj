#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll t,m,n,par[20005],x,disc[20005],low[20005],z;
map<string,ll>mp;
string s,p;
vector<ll>g[20005];
map<ll,ll>vis;
stack<ll>st;
bool ck[20005];
void targan(ll u,ll tm)
{
    disc[u]=low[u]=++tm;
    st.push(u);
    ck[u]=true;
    for(ll i=0;i<g[u].size();i++)
    {
        ll v=g[u][i];
        if(disc[v]==-1)
        {
            targan(v,tm);
            low[u]=min(low[u],low[v]);
        }
        else if(ck[v]==true)
            low[u]=min(low[u],disc[v]);
    }
    if(disc[u]==low[u])
    {
        while(st.top()!=u)
        {
            ck[st.top()]=false;
            st.pop();
        }
        ck[st.top()]=false;
            st.pop();
    }

}
int main()
{
    ll i,j;
    cin>>t;
    while(t--)
    {
        cin>>m;
        j=0;
        while(m--)
        {
            cin>>s>>p;
            if(!mp[s])
                mp[s]=++j;
            if(!mp[p])
                mp[p]=++j;
            g[mp[s]].pb(mp[p]);
        }
        memset(disc,-1,sizeof(disc));
        memset(low,-1,sizeof(low));
        memset(ck,false,sizeof(ck));
        for(i=1;i<=j;i++)
        {
            if(disc[i]==-1)
            targan(i,0);
        }
        ll q=0;
        for(i=1;i<=j;i++)
        {
            if(low[i]<disc[i])
            {
                q=1;
                break;
            }
        }
        if(q==1)
            cout<<"Case "<<++z<<": No\n";
        else
        cout<<"Case "<<++z<<": Yes\n";
        for(i=1;i<=j;i++)
            g[i].clear();
        mp.clear();
    }
}
