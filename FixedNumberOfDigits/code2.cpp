/*
*Problem Link:
 You are writing down numbers in increasing order, starting with start and increasing by step. You stop after writing down numberOfDigits digits total. You stop immediately, even if it's in the middle of a number.
 Calculate and return the last number you wrote. 
*/


#include <bits/stdc++.h>
using namespace std;
//Defines
#define MOD 1000000007
#define ll long long int
#define for_i(x,i,l) for(size_t x = i; x<l;x++)
#define for_i_neg(x,i,l) for(int x = l; x>=i;x--)
#define for_map(x,mp) for(auto x=mp.begin();x!=mp.end();x++)
#define mp(x,y) make_pair(x,y)
#define debug(x) std::cout << #x <<'\t'<<x<< std::endl
#define inll(x) scanf("%lld",&x)
#define outll(x) printf("%lld\n",x)
#define pb(x) push_back(x)
//usable Functions
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}
void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}
ll b_search(vector<ll> v , ll x){ll h,l,m;h=v.size()-1;l=0;while(l<=h){m=(l+h)/2;if(v[m]==x)return m;if(v[m]>x) h=m-1;else l=m+1;}return -1;}

class FixedNumberOfDigits
{
  public:
  ll count_digit(ll n)
  {
    ll count=0;
    if(n==0)
      return 1;
    while(n>0)
    {
      n/=10;
      count++;
    }
    return count;
  }

  ll sum (ll s,ll st,ll limit)
  {
    bool  flag=true;
    ll c,r;
    while (flag)
    {
      r=0;
      vector<int> v;
      c=count_digit(s);
    //   debug(c);
    // debug(limit);
      if(limit-c<=0)
      {
        if(s==0)
          v.push_back(0);
        else
        {
          while(s>0)
          {
            v.push_back(s%10);
            s/=10;
          }
        }
        reverse(v.begin(),v.end());
        for_i(i,0,limit)
        {
          r=r*10+v[i];
        }
        flag=false;
      }
      else
      {
        limit-=c;
        s+=st;
      }
    }
          return r;
  }

};


int main()
{
  ll s,st,d;
  ll t;
  cin>>t;
  while(t--)
  {
    inll(s);
    inll(st);
    inll(d);
    // debug(s);
    // debug(st);
    // debug(d);
    FixedNumberOfDigits o;
    outll(o.sum(s,st,d));
  }
  return 0;
}
