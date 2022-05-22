/*
Problem Link:
Ternary search is one of many algorithms in which we need to split a range of integers into three equal (or almost equal) parts. That will be your task in this problem.
A half-open interval [x,y) is the set of integers that are greater than or equal to x and strictly less than y. Hence, [x,y) = { x, x+1, x+2, ..., y-2, y-1 }. For example, [3,7) = { 3, 4, 5, 6 }.
You are given two ints a and d. These define the half-open interval [a,d). This interval contains n = d-a numbers. Your task is to split this interval into three parts: [a,b), [b,c), and [c,d). Each of these intervals must contain at least (n div 3) elements.
Return {b, c}. That is, return a int[] with two elements, the first of which is b and the second is c. If there are multiple valid solutions, you may return any one of them. 
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
void print_v_int(vector<int> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}
ll b_search(vector<ll> v , ll x){ll h,l,m;h=v.size()-1;l=0;while(l<=h){m=(l+h)/2;if(v[m]==x)return m;if(v[m]>x) h=m-1;else l=m+1;}return -1;}

class ThreePartSplit 
{
  public:
  std::vector<int> split(int a,int b)
    {
      std::vector<int> v;
      int n= b-a;
      n=n/3;
      v.push_back(a+n);
      v.push_back(a+n+n);
      return v;
    }
};

int main()
{
  int a,b;
  cin>>a>>b;
  ThreePartSplit o;
  print_v_int(o.split(a,b));
  return 0;
}
