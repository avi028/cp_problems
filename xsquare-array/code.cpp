/*
*Problem Link:
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-two-arrays/description/
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
  ll n,q,t,l,r;
  cin>>n>>q;
  vector<ll> a(n);
  vector<ll> b(n);
  for_i(i,0,n)
  {
    cin>>a[i];
  }
  for_i(i,0,n)
  {
    cin>>b[i];
  }
  for_i(i,1,n)
  {
    a[i]=a[i]+b[i];
    b[i]=a[i]-b[i];
    a[i]=a[i]-b[i];
    i++; 
  }
  for_i(i,1,n)
  {
      a[i]+=a[i-1];
      b[i]+=b[i-1];
  }
  for_i(itrq,0,q)
  {
    cin>>t>>l>>r;
    if(t==1)
    {
      if(l&1)
      {
        if(l>1)
          cout<<a[r-1]-a[l-2];
        else
          cout<<a[r-1];
      }
      else
        cout<<b[r-1]-b[l-2];  
    }
    else
    {
      if(l&1)
      {
        if(l>1)
          cout<<b[r-1]-b[l-2];
        else
          cout<<b[r-1];
      }
      else
        cout<<a[r-1]-a[l-2];  
    }
    cout<<endl;
  }
  return 0;
}
