/*
*Problem Link:
https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c
*/


#include <bits/stdc++.h>
using namespace std;
//Defines
#define MOD 1000000007
#define ll long long int
#define for_i(x,i,l) for(ll x = i; x<l;x++)
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
	ll t,x,y,j,sum;
	string s,new_s;
	cin>>t;
	for_i(itr,1,t+1)
	{
		cin>>x>>y>>s;
		new_s ="";
		sum=0;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]=='C'||s[j]=='J')
				new_s = new_s+s[j];				
		}
		//cout<<new_s<<endl;
		for(int j=0;j<new_s.length();j++)
		{
			if(new_s[j]=='C'&& new_s[j+1]=='J')
			{
			sum+=x;
			}
			else if(new_s[j]=='J'&& new_s[j+1]=='C')
			{
			sum+=y;
			}
		}
		printf("Case #%lld: %lld\n",itr,sum);
	}
}
