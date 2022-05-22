/*
*Problem Link:
https://www.hackerearth.com/challenges/competitive/july-easy-20/algorithm/jetha-and-cars-2d835131/
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
  ll n,t;
  cin>>t;
  for_i(itr,0,t)
  {
    cin>>n;
    vector<ll>v(n);
    for_i(i,0,n)
    cin>>v[i];
    sort(v.begin(),v.end());
    
    ll ans=v[0];
    ll last=v[0];
    for_i(i,1,n)
    {
      if(last!=v[i])
       {  
         last = v[i];
          ans+=v[i];
      }
    }
    printf("%lld\n",ans);
  }
}
