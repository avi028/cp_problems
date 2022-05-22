/*
*Problem Link:
https://www.codechef.com/JULY20B/problems/DRCHEF
*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define for_i(x,i,l) for(size_t x = i; x<l;x++) 
#define for_i_neg(x,i,l) for(int x = l; x>=i;x--) 
#define for_map(x,mp) for(auto x=mp.begin();x!=mp.end();x++)
#define mp(x,y) make_pair(x,y)
#define debug(x) std::cout << #x <<x<< std::endl
#define inll(x) scanf("%lld",&x) 
#define outll(x) printf("%lld\n",x)
#define pb(x) push_back(x)

//usable Functions
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}
ll b_search(vector<ll> v , ll x){ll h,l,m;h=v.size()-1;l=0;while(l<=h){m=(l+h)/2;if(v[m]==x)return m;if(v[m]>x) h=m-1;else l=m+1;}return -1;}
void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}


int main()
{
  ll t,n,x,in,i,cnt,ans;

  vector<ll> a;
  inll(t);
  for_i(itr,0,t)
  {
    ans=0;
    n=0;
    x=0;
    a.clear();  
    inll(n);
    inll(x);
    for_i(i,0,n)
     {
       inll(in);
       a.pb(in);
     } 
    sort(a.begin(),a.end()); 
//    print_v(a);
    i=0;
    if(x>=a[n-1])
      ans=n;
    else if(x>=2*a[n-1])
      ans=n+1;
    else
    {
      // ans=n;
      // if(x<a[0])
      // {
      //   while(a[0]>x)
      //   {
      //     x=x*2;
      //     ans++; 
      //   }
      //   if(x==a[0])
      //   {
      //     x=a[0]*2;
      //   }
      //   else if(x>2*a[0])
      //   {
      //     x=2*a[0];
      //   }
      // }
      i=-1;
      cnt=0;
      ans=n;
      while(i+1< n )
      {
        if(x>=a[i+1])
        {
          i++;
          continue;
        }
        if(i>=0 && x<2*a[i])
        {
          x=2*a[i];
          cnt++;
//          ans++;
          continue;
        }
        if (i+1<n-1 && x<=a[n-1]/2)
        {
          x*=2;
          ans++;
          continue;
        }  
        if(i+1<n-1 && x>a[n-1]/2)
        {
          ans++;
          break;
        }
        if(i+1 == n-1)
        {
          while(x < a[n-1])
          {
             x*=2;
             ans++;   
          }
 //         ans++;
          cnt++;
          break;
        }
      }   
      //   debug(n);
      //  debug(cnt);
      //  debug(ans); 
    }
    outll(ans);
  }
  return 0;
}
