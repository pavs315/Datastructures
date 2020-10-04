#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
 
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size() 
 
ll ans;
vector<ll>Q;
vector<pll>edge[100005];
ll vis[100005];
 
void dfs(ll idx,ll l,ll r)
{
	vis[idx]=1;
	if(l>r || l<0 || r<0)
		return;
	ll now=r;
	for(ll i=0;i<sz(edge[idx]);i++)
	{
		if(!vis[edge[idx][i].ss])
		{
			ll x=edge[idx][i].ff;
			ll y=upper_bound(Q.begin()+l,Q.begin()+now+1,x)-Q.begin();
			dfs(edge[idx][i].ss,y,now);
			now=y-1;
		}
	}
	ans+=(now-l+1)*idx;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	ll n,i,j,k,x,y,m,q,w;
 
	
		cin >> n >> q;
		for(i=1;i<=n;i++)
			vis[i]=0,edge[i].clear();
 
		Q.clear();
 
		for(i=1;i<=n-1;i++)
		{
			cin >> x >> y >> w;
			edge[x].pb(mp(w,y));
			edge[y].pb(mp(w,x));
		}
 
		for(i=0;i<q;i++)
		{
			cin >> x;
			Q.pb(x);
		}
 
		sort(all(Q));
		for(i=1;i<=n;i++)
		{
			sort(all(edge[i]));
			reverse(all(edge[i]));
		}
 
		ans=0;
		dfs(1,0,q-1);
		cout<<ans<<endl;
	
}