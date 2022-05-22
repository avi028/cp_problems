/*
*Problem Link:
https://www.codechef.com/AUG20B/problems/CHEFWED
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
int Nmax = 10003;
int Fmax=102;

int main()
{
	ll x,t,n,k,ans;
	inll(t);
	vector<ll> v(Nmax,0);
	vector<ll> fcount(Fmax,0);
	for_i(itr,0,t)
	{
		inll(n);
		inll(k);
		vector< vector<ll> >v_set (Nmax);
		fill(v.begin(),v.end(),0);
		fill(fcount.begin(),fcount.end(),0);
		ans=1;

		for_i(i,0,n)
			cin>>v[i];
		int iv=0;
		for_i(i,0,n)
		{
			fcount[v[i]]++;
			if(fcount[v[i]]>1)
			{
				fill(fcount.begin(),fcount.end(),0);
				iv++;
				fcount[v[i]]++;
				v_set[iv].push_back(v[i]);
			}
			else
			{
				v_set[iv].push_back(v[i]);
			}
		}
		//~ for_i(i,0,iv+1)
		//~ {
			//~ print_v(v_set[i]);
		//~ }

		fill(fcount.begin(),fcount.end(),0);
		for_i(j,0,v_set[0].size())
			fcount[v_set[0][j]]++;
		ll qcount=0;
		ll tcount=1;
		for_i(i,1,iv+1)
		{
			ll count=0;
			for_i(j,0,v_set[i].size())
			{
				fcount[v_set[i][j]]++;
				if(fcount[v_set[i][j]]==2)count+=2;
				else if(fcount[v_set[i][j]] > 2)count+=1;
			}
			if((k*tcount + qcount+count) > (k*(tcount+1)+qcount))
			{
				tcount++;
				print_v(v_set[i]);
				fill(fcount.begin(),fcount.end(),0);
				for_i(j,0,v_set[i].size())
					fcount[v_set[i][j]]++;
			}
			else
			{
				qcount+=count;
			}
		}
		ans=k*tcount+qcount;
		cout<<ans<<endl;
		v_set.clear();
	}
	v.clear();
	fcount.clear();
	return 0;
}
