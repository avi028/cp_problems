/*
*Problem Link:
https://www.codechef.com/SEPT20B/problems/ADAMAT
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
	ll t,n,ans,flag,sec_flag;
	inll(t);
	for_i(itr,0,t){
		inll(n);
		vector< vector<ll> > v (n,vector<ll>(n));
		for_i(i,0,n){
			for_i(j,0,n)
				cin>>v[i][j];
		}
		ans=0;
		flag=-1;
		sec_flag=0;
		for_i(i,1,n)
		{
			sec_flag=0;
			while(v[0][i]!=i+1 && i<n)
			{
				i++;
				sec_flag=1;
			}
			if(sec_flag==1)
				if(flag==1)
					ans+=2;
				else
					ans+=1;
			if(v[0][i]==i+1 && i<n)
				flag=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
