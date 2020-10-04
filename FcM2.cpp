#include<iostream>
#include<vector>
using namespace std;
#define max 1000007

 vector<int> G[max];

int main()
{
    int n,m;
    cin>>n>>m;
    int i,j;
    int arr[n+1];
    
    
    for(i=1; i<=n;i++)
    {
       cin>>arr[i];
    }
    int u,v;
    int x,y;
    int index;
    index=arr[1];
    for(i=2;i<=n;i++)
    {
        if(index>arr[i])
        {
        index=arr[i];
        }
    }
   
   
    int cnt,cnt2;

    for(i=1;i<=m;i++)
    {

           cnt=0;
           cnt2=0;
        cin>>u>>v;
        x=arr[u];
        y=arr[v];
      
        if(x!=y)
        {
          
          
	  
      
       for(j=1;j<=G[y].size();j++)
         {
             if(G[y][j]==x)
             cnt2++;
         }
           if(cnt2==0)
          G[y].push_back(x);
          for(j=1;j<=G[x].size();j++)
         {
             if(G[x][j]==y)
             cnt++;
         }
          if(cnt==0)
          G[x].push_back(y);
         
         
         
        }
    }
    int ans;
    ans=0;
    for(i=1;i<=max;i++)
     { int x;
        x=G[i].size();
        if(x>ans)
        {
        ans=x;
        index=i;
        }

     }
 cout<<index<<endl;
 return 0;
}
