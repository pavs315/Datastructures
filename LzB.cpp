#define ll long long int
#include<iostream>
#include<vector>
using namespace std;
#define ld long double
#define MAX 1000007
#define pb push_back
ll vis[MAX],a[MAX];
vector<ll> v;
vector<ll> visited;
ll cycledetect(ll k);

ll length(vector<ll>vecto)
{
    return vecto.size();
}

void pop(vector<ll>vecto)
{
      vecto.pop_back();
}
ll arr[100005];
ll cycledetect(ll k)
{
	vis[k]=2;
	v.pb(k);
	ll b=a[k];
     ll flag1,flag2,flag3;

	if(vis[b]!=3)
    {
    flag1=1;
    }
    else
    {
        flag1=0;
    }
    if(flag1==1)
	{
		
        
		if(vis[b]!=7)
        {
            flag2=1;
        }
        if(vis[b]==7)
        {
            flag2=0;
        }
        if(flag2==1)
		{
			ll len=length(v)-1;
			while(v[len]!=b)
			{
				arr[v[len]]=v[len];
				vis[v[len]]=3;
				len--;
			}
			arr[v[len]]=v[len];
			vis[v[len]]=3;
			
		}

        else
		{
			v.push_back(k);
			cycledetect(b);}
	}
	if(arr[k]==-1)
		arr[k]=arr[b];
	vis[k]=3;
	return 0;
}
int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
	ll n;
	cin>>n;
    ll i;
	visited=vector<ll>(n+1,0);
	for(i=0;i<n+1;i++)
    {
		vis[i]=7;
		arr[i]=-1;
    }
	for(i=1;i<n+1;i++)
    {
		cin>>a[i];
    }
	for( i=1;i<n+1;i++)
	{
		if(vis[i]==7)
        {
			v.clear();
			cycledetect(i);
        }
	}
	for( i=1;i<n+1;i++)
    {
	cout<<arr[i]<<" ";
    }
	cout<<endl;
 }
}
