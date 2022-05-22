/*
*Problem Link:
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/hasan-and-trip-1/editorial/
*/


#include <bits/stdc++.h>
using namespace std;
//Defines
#define inf 1000000000
#define MOD 1000000007
#define ll long long int
#define for_i(x,i,l) for(size_t x = i; x<l;x++) 
#define for_i_neg(x,i,l) for(int x = l; x>=i;x--) 

#define debug(x) std::cout << #x <<x<< std::endl
//usable Functions
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}

void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}
void print_vd(vector<double> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}

double ED(ll x1,ll y1,ll x2,ll y2)
{
  return (double)sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}


int main()
{
  ll n;
  cin>>n;
  vector<double> x(n);
  vector<double> y(n);
  vector<double> f(n);
  vector<double> dp(n);
  for_i(i,0,n)
    cin>>x[i]>>y[i]>>f[i];
    
  for_i(i,0,n)
    dp[i]=-1.0*inf;

  dp[0]=0.0;
  for_i(i,0,n)
  {
    dp[i]+=f[i];
    for_i(j,i+1,n)
      dp[j] = max(dp[j],dp[i]-(double)ED(x[i],y[i],x[j],y[j]));
  }
  print_vd(dp);
  printf("%.6lf",dp[n-1]);
  return 0;
}
