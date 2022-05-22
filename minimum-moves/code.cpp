/*
*Problem Link:
https://www.hackerearth.com/challenges/competitive/july-easy-20/algorithm/akash-and-diagnol-moves-dfc4f00f/
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
  ll t,X,Y;
  cin>>t;
  for_i(itr,0,t)
  {
     cin>>X>>Y;
     ll ans =-1;
    if(X >= Y && X>=0 && Y>=0)
      ans =X;
    cout<<ans<<endl;  
  }
}
