/*
*Problem Link:
https://www.codechef.com/SEPT20B/problems/COVID19B
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
	ll test,n;
	inll(test);

	set<double> t_set;
	set<double>::iterator itr_tset;

	for_i(i,1,7)
		for_i(j,i+1,7)
			for_i(k,1,5)
				t_set.insert(k*1.0/(j-i));

	for_i(itr,0,test)
	{
		inll(n);
		vector<ll> v(n);
		for_i(i,0,n)
			cin>>v[i];

		vector< vector<double> > ans (t_set.size(),vector<double>(n) );
		int it=0;
		for(itr_tset=t_set.begin();itr_tset!=t_set.end();itr_tset++)
		{
			double time = *itr_tset;
			for_i(i,0,n)
			{
				ans[it][i]=(i+1)+v[i]*time;
			}
			it++;
		}
		vector<ll> v2(n,0);
		for_i(i,0,n)
		{
			vector<ll> v1(n,0);
			v1[i]=1;
			for_i(j,0,t_set.size())
			{
				for_i(k,0,n)
				{
					for_i(l,0,n)
					{
						if(abs(ans[j][k]-ans[j][l])<1e-9 && v1[k]==1 && k!=l)
						{
							v1[l]=v1[k];
						}
					}
				}
			}
			for_i(j,0,n)
				v2[i]+=v1[j];
		}
		ll mn=n,mx=0;
		for_i(i,0,n)
		{
			mx=mx<v2[i]?v2[i]:mx;
			mn=mn>v2[i]?v2[i]:mn;
		}
		cout<<mn<<" "<<mx<<endl;
	}
	return 0;
}
