#include<iostream>
#include<deque>
using namespace std;
#define ll long long int

deque<ll>s1;
deque<ll>s2;

void showstack(deque <ll> st) 
{ 
    while (!st.empty()) 
    { 
        cout <<  st.front()<<" "; 
        st.pop_front(); 
     
    } 
     
} 

int main()
{
 ll q;
    cin>>q;
     char var;
     ll num,k,p,s,t,u,v;
    while(q--)
    {
       cin>>var;
       if(var=='a')
       {
          cin>>num;
          s2.push_back(num);
          if(s2.size()-s1.size()==0 || s2.size()-s1.size()==1)
          {
          continue;
          }
           else if (s1.size()>s2.size())
          {
          k=s1.back();
          s1.pop_back();
          s2.push_front(k);
          }
           else if(s2.size()-s1.size()>1)
          {
            p=s2.front();
            s2.pop_front();
            s1.push_back(p);
          }
       }
       if(var=='t')
       {
           s2.pop_back();
            if(s2.size()-s1.size()==0 || s2.size()-s1.size()==1)
          {
          continue;
          }
           else if (s1.size()>s2.size())
          {
          s=s1.back();
          s1.pop_back();
          s2.push_front(s);
          }
           else if(s2.size()-s1.size()>1)
          {
            t=s2.front();
            s2.pop_front();
            s1.push_back(t);
          }
       }
       if(var=='e')
       {
           s1.swap(s2);
            if(s2.size()-s1.size()==0 || s2.size()-s1.size()==1)
          {
          continue;
          }
           else if (s1.size()>s2.size())
          {
          u=s1.back();
          s1.pop_back();
          s2.push_front(u);
          }
           else if(s2.size()-s1.size()>1)
          {
            v=s2.front();
            s2.pop_front();
            s1.push_back(v);
          }
       }   
    }
     ll l;
       l=s1.size()+s2.size();
       cout<<l<<endl;
       showstack(s1);
    
       showstack(s2);
       cout<<endl;
} 