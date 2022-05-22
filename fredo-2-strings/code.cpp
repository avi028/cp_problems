/*
*Problem Link:
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/fredo-and-two-strings-247e6c24/description/
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
  ll n,n2;
  string s1,s2;
  while(cin>>s1>>s2)
  {
    n = s1.size();
    n2 = s2.size();
    vector<ll> f(n,0);
    vector<ll> b(n,0);
    ll j;
    j=0;
    for_i(i,0,n)
      f[i]=(j <n2 && s1[i]==s2[j])?++j:j;
    j=0;
    for_i_neg(i,0,n)
      b[i]=(j<n2 && s1[i]==s2[n2-j-1])?++j:j;

    print_v(f); 
    print_v(b);    
  } 
  return 0;
}
