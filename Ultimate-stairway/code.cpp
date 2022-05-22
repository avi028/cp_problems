/*
*Problem Link:
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/ultimate-stairway-to-heaven/
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
   ll n;
  while(cin>>n)
  { 
    vector<ll> v(n);
    vector<ll> temp(n);
    vector<ll> dp(n);
  
    for_i(i,0,n)
    {
      scanf("%lld",&v[i]);
      temp[i]=0;
    }
    dp[0]=1;
    ll sum=0;
    for_i(i,0,n-1)
    {
      temp[i+1]=(temp[i+1]+dp[i])%MOD;
      if(i+1+v[i]<n)
        temp[i+1+v[i]]= (MOD+temp[i+1+v[i]]-dp[i])%MOD ;
      sum=(sum+temp[i+1])%MOD;
      dp[i+1]=sum;    
    }
    cout<<dp[n-1]<<endl;
  }
  return 0;
}