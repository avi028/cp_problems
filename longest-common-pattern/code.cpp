/*
*Problem Link:
https://www.codechef.com/problems/LCPESY
*/

#include <bits/stdc++.h>
using namespace std;
//Defines
#define MOD 1000000007
#define ll long long int
#define for_i(x,i,l) for(size_t x = i; x<l;x++)
#define for_i_neg(x,i,l) for(int x = l; x>=i;x--)
#define for_map(x,mp) for(auto x=mp.begin();x!=mp.end();x++)
#define mp(x,y) make_pair(x,y)
#define debug(x) std::cout << #x <<'\t'<<x<< std::endl
#define inll(x) scanf("%lld",&x)
#define outll(x) printf("%lld\n",x)
#define pb(x) push_back(x)
//usable Functions
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}
void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}
ll b_search(vector<ll> v , ll x){ll h,l,m;h=v.size()-1;l=0;while(l<=h){m=(l+h)/2;if(v[m]==x)return m;if(v[m]>x) h=m-1;else l=m+1;}return -1;}

int main()
{
  ll t,na,nb,ans;
  inll(t);
  string a,b;
  map<char,ll> ma,mb;
  for_i(itr,0,t)
  {
    a="";
    b="";
    na=0;
    nb=0;
    ans=0;
    ma.clear();
    mb.clear();
    cin>>a;
    cin>>b;
    na=a.size();
    nb=b.size();

    for_i(i,0,na)
    {
      ma[a[i]]++;
      mb[a[i]]=0;
    } 
    for_i(i,0,nb)
    {
      mb[b[i]]++;
      if(!(ma[b[i]]>0))
        ma[b[i]]=0;
    } 
    ans=0;
    for_map(i,ma)
    {
      ans+=min(i->second,mb[i->first]);
    }
    outll(ans);
  }
  return 0;
}
