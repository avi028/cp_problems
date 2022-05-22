/*
*Problem Link:
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/intelligent-girl-1/
*/


#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define for_i(x,i,l) for(size_t x = i; x<l;x++) 
#define for_i_neg(x,i,l) for(int x = l; x>=i;x--) 
#define debug(x) std::cout << #x << std::endl

void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<" ";cout<<endl;}
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}


int main()
{
  
  string s;
  cin>>s;
  ll n = s.size();
  ll count=0;
  vector<ll> v (n);
  for_i_neg(i,0,n-1)
  {
    if( !(((int)(s[i]-48))&1) )
    {
      count++;
    } 
    v[i]=count;
  }
  print_v(v);
  return 0;
}
