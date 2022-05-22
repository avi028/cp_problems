/*
*Problem Link:
https://www.codechef.com/JULY20B/problems/CHEFSTR1
*/


#include <bits/stdc++.h>
using namespace std;
//Defines
#define MOD 1000000007
#define ll long long int
#define for_i(x,i,l) for(size_t x = i; x<l;x++) 
#define for_i_neg(x,i,l) for(int x = l; x>=i;x--) 

#define debug(x) std::cout << #x <<x<< std::endl
//usable Functions
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}

void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}

int main()
{
  ll t,n,ans;
  scanf("%lld",&t);
  for_i(itr,0,t)
  {
    scanf("%lld",&n);
    vector<ll> v(n);
    for_i(i,0,n)
      scanf(" %lld",&v[i]);
    ans=0;
    for_i(i,1,n)
    {
      ans+=abs(v[i]-v[i-1])==0?abs(v[i]-v[i-1]):abs(v[i]-v[i-1])-1;
    }
      printf("%lld\n",ans);
  }
  return 0;
}
