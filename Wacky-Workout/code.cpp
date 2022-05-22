/*
*Problem Link:
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/angry-neighbours/
*/


#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define for_i(x,i,l) for(size_t x = i; x<l;x++) 
using namespace std;

long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=((result%MOD)*(x%MOD))%MOD;x=(x*x)%MOD;b/=2;}return result;}

void print_m(ll z[][2])
{
  for_i(i,0,2)
  {
    for_i(j,0,2)
    {
      cout<<z[i][j]<<" ";
    }
    cout<<endl;
  }
}

void mat_copy(ll s[][2],ll d[][2])
{
  for_i(i,0,2)
  {
    for_i(j,0,2)
    {
      d[i][j]=s[i][j];
    }
  }
}

void mul(ll z[][2],ll a[][2], ll b[][2])
{
  ll t[2][2];
  ll t2[2][2];
  mat_copy(b,t);
  mat_copy(a,t2);
  for (size_t i = 0; i < 2; i++)
  {
    for(size_t j=0;j<2;j++)
    {
      // a11b11 + a12b21
       z[i][j] =  ((t2[i][0]%MOD*t[0][j]%MOD)%MOD+(t2[i][1]%MOD*t[1][j]%MOD)%MOD)%MOD;
    }
  }
}

void mat_power(ll z[][2],ll n,ll result[][2])
{
  while(n>0)
  {
    if(n&1)
    {
      mul(result,z,result);
    }    
    mul(z,z,z);
    n/=2;
  } 
}

int main()
{
  ll t,n,ans;
  cin>>t;
  
  for (size_t itr = 0; itr < t; itr++)
  {
    cin>>n;
    ll result[2][2] = {1,0,0,1};    
    ll z[2][2] = {1,1,1,0};
    mat_power(z,n,result);
    ans = (result[0][0]%MOD + result[0][1]%MOD)%MOD;  
    cout<<ans<<endl;
  }
  return 0;
}
