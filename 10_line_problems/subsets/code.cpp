/*
*Problem Link:

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
void print_v(vector<int> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}
ll b_search(vector<ll> v , ll x){ll h,l,m;h=v.size()-1;l=0;while(l<=h){m=(l+h)/2;if(v[m]==x)return m;if(v[m]>x) h=m-1;else l=m+1;}return -1;}

void subset(vector<int>sset, vector<int> v, int l, int h )
{
  if(l==h)
  return;
  else
  {
    for_i(i,l,h)
    {
      vector<int> sset_copy;
      for_i(j,0,sset.size())
      {
        sset_copy.push_back(sset[j]);
      }
      sset_copy.push_back(v[i]);
      subset(sset_copy,v,i+1,h);
    }
  }
  if(sset.size()>0)
    print_v(sset);
}

int main()
{
  int n;
  cin>>n;
  vector<int> v;
  vector<int>sset;
  n+=1;
  for_i(i,1,n)
    v.push_back(i);
  subset(sset,v,0,n);  
  return 0;
}
