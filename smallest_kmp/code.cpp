/*
*Problem Link:
https://www.codechef.com/AUG20B/problems/SKMP
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
#define scan(str) cin>>str;cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//usable Functions
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}
void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}
ll b_search(vector<ll> v , ll x){ll h,l,m;h=v.size()-1;l=0;while(l<=h){m=(l+h)/2;if(v[m]==x)return m;if(v[m]>x) h=m-1;else l=m+1;}return -1;}

int main()
{
  ll t,flag,n,n2,pit_stop;
  string s,s2;
  inll(t);
  for_i(itr,0,t)
  {
    vector<int> v (26,0);
    cin>>s;
    cin>>s2;
    n=s.length();
    n2=s2.length();
    for_i(i,0,n)
    {
      v[int(s[i]-97)]++;
    }
    for_i(i,0,n2)
    {
      v[(int)(s2[i]-97)]--;
    }
    pit_stop = (int)(s2[0]-97);
    for_i(i,0,pit_stop)
    {
      if(v[i]>0)
        for_i(j,0,v[i])
          cout<<(char)(i+97);
    }
    flag=0;
    for_i(i,1,n2)
    {
      if(s2[i-1]>s2[i])
        {
          flag=1;
          break;
        }
      if(s2[i-1]<s2[i])
        {
          flag=0;
          break;
        }
    }
    if(flag==1)
    {
      cout<<s2;
      if(v[pit_stop]>0)
        for_i(i,0,v[pit_stop])
            cout<<(char)(pit_stop+97);
    }
    else
    {
      if(v[pit_stop]>0)
        for_i(i,0,v[pit_stop])
            cout<<(char)(pit_stop+97);      
      cout<<s2;
    }
    for_i(i,pit_stop+1,26)
    {
      if(v[i]>0)
        for_i(j,0,v[i])
          cout<<(char)(i+97);
    }
    cout<<endl;
    v.clear();
  }
  return 0;
}
