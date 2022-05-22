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
	long long int t,n,itr,i,debug_flag,j,min,min_itr,loop_count,sum,temp;
	cin>>t;
	debug_flag=1;
	for_i(itr,1,t+1)	
	{
		cin>>n;
		sum=0;
		loop_count=0;
		vector<long long int> v(n);
		for_i(i,0,n)
		{	
			cin>>v[i];
		}
		for_i(i,0,n-1)
		{
			min=MOD;
			min_itr=i;
			for_i(j,i,n)
			{
				if(min>v[j])	
				{
					min=v[j];
					min_itr=j;
				}
			}			
			loop_count = min_itr-i+1;
		//	debug(min_itr);
		//	debug(min);
		//	debug(loop_count);
			for(int j=0;j<loop_count/2;j++)	
			{
				temp = v[i+j];
				v[i+j]=v[min_itr-j];
				v[min_itr-j] = temp;
			}
			if(debug_flag == 1)
			{
				print_v(v);
			}
			sum+=loop_count;
		}
		printf("Case #%lld: %lld\n",itr,sum);
	}
	return 0;
}
