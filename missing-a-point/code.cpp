/*
*Problem Link:
https://www.codechef.com/JULY20B/problems/PTMSSNG
*/


#include <bits/stdc++.h>
using namespace std;
//Defines
#define MOD 1000000007
#define ll long long int
#define for_i(x,i,l) for(size_t x = i; x<l;x++) 
#define for_i_neg(x,i,l) for(int x = l; x>=i;x--) 
#define mp make_pair
#define debug(x) std::cout << #x <<x<< std::endl
//usable Functions
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}

void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}

int main()
{
  ll t,n;
  scanf("%lld",&t);
  for_i(itr,0,t)
  {
   scanf("%lld",&n);
   n = 4*n-1;
   vector<ll> v1(n,0);
   vector<ll> v2(n,0);
   for_i(i,0,n)
   {
     scanf("%lld %lld",&v1[i],&v2[i]);
   }
   sort(v1.begin(),v1.end());
   sort(v2.begin(),v2.end());
  print_v(v1);
  print_v(v2);
   ll count=1; 
   ll flag=0;
   ll x;
   for_i(i,1,n)
   {
     if (v1[i]==v1[i-1])
        count++;
     else
     {
        if(count%2>0)
        {
          x = v1[i-1];
          flag=1;
          break;
        }
        count=1;   
     }
   }
  if(count%2>0 && !flag)
  {
    x = v1[n-1];
  }

   count=1;
   flag=0;
   ll y;
   for_i(i,1,n)
   {
     if (v2[i]==v2[i-1])
        count++;
     else
     {
        if(count%2>0)
        {
          y = v2[i-1];
          flag=1;
          break;
        }
        count=1;   
     }
   }
  if(count%2>0 && !flag)
  {
    y = v2[n-1];
  }
    printf("%lld %lld\n",x,y);
  }
  return 0;
}
