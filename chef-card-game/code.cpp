/*
*Problem Link:
https://www.codechef.com/JULY20B/problems/CRDGAME
*/


#include <bits/stdc++.h>
using namespace std;
//Defines
#define MOD 1000000007

#define s_lld(val) scanf("%lld",&val)
#define s_d(val) scanf("%d",&val)
#define s_llds scanf(" %lld",&val)
#define p_lld(val) printf("%lld",val)
#define p_nl printf("\n")

#define ll long long int
#define for_i(x,i,l) for(size_t x = i; x<l;x++) 
#define for_i_neg(x,i,l) for(int x = l; x>=i;x--) 

#define debug(x) std::cout << #x <<x<< std::endl
//usable Functions
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}

void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}

int dsum(ll a)
{
  ll sum=0;
  while(a>0)
  {
    sum+=a%10;
    a=a/10;
  }
  return sum;
}

int main()
{
  ll t,n,a,b,ans,ms,cs;
  s_lld(t);  
  for_i(itr,0,t)
  {
    s_lld(n);
    cs=ms=0;
    for_i(i,0,n)
    {
      scanf("%lld %lld",&a,&b);
      a = dsum(a);
      b = dsum(b);
      cs += a>=b?1:0;
      ms += b>=a?1:0;
    }
    if(cs>ms)
      printf("0 %lld\n",cs);
    else if(cs==ms)
      printf("2 %lld\n",cs);
    else
      printf("1 %lld\n",ms);  
  }
  return 0;
}
