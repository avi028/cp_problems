/*
*Problem Link:
https://www.codechef.com/COOK122B/problems/BULBS
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
	ll t,st,k,n,count;
	string s;
	cin>>t;

	for_i(itr,0,t)
	{
		cin>>n>>k;
		cin>>s;
		vector< pair<ll,ll> >v ;
		for_i(i,0,n)
		{
			if((i==0 && s[i]=='0') || (s[i]=='1' && i<n-1 && s[i+1]=='0'))
			{
				st=i;
				i++;
				count=0;
				if(s[st]=='0')
				count=1;

				while(s[i]=='0' && i<n)
				{
					count++;
					i++;
				}
				i--;
				v.push_back(mp(count,st));
			}
		}
		sort(v.begin(),v.end());
		//~ for_i(i,0,v.size())
			//~ cout<<v[i].first<<" "<<v[i].second<<endl;

		string s1="";
		for_i(i,0,n)s1=s1+'1';
		//~ cout<<s<<endl<<s1<<endl;
		for(ll i=v.size()-1;i>=0;i--)
		{
			if((k-2)>=0)
			{
				ll j;
				for(j=v[i].second+1;j<(v[i].second+1+v[i].first);j++)
				{
					s1[j]='0';
				}
				if(j==n || v[i].second==0)
					k=k-1;
				else
					k-=2;
			}
		}
		//~ cout<<s<<endl<<s1<<endl;
		//~ debug(k);
		if(k>0)
		{
			if(s[n-1]=='0' && s1[n-1]=='1')
			{
				k--;
				s1[n-1]=s[n-1];
			}
			if(s[0]=='0' && s1[0]=='1')
			{
				k--;
				s1[0]=s[0];
			}
		}
		//~ cout<<s<<endl<<s1<<endl;
		count=0;
		for_i(i,0,n)
		{
			if(s[i]!=s1[i])
			count++;
		}
		cout<<count<<endl;
 	}
	return 0;
}
