/*
*Problem Link:
https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7
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
	ll t,n,c,max,loop_count,min_itr,temp;
	cin>>t;
	for_i(itr,1,t+1)
	{
		cin>>n>>c;
		//n-=1;
		vector<ll> v(n-1,1);
		c-=(n-1);
		max=n-1;
		if(c>=0 && c<=(((n*(n-1))/2)))
		{
			for_i(i,0,n)
			{
				if(c<=max){v[i]+=c;break;}
				v[i]+=max;
				c-=max;
				max--;
			}
			//print_v(v);
			//n+=1;
			vector<ll> arr(n,0);
			for_i(i,0,n)
				arr[i]=i+1;
			//print_v(arr);

			for(int i=n-2;i>=0;i--)
			{
				loop_count = v[i];
				min_itr = loop_count+i -1;

				for(int j=0;j<loop_count/2;j++)	
				{
					temp = arr[i+j];
					arr[i+j]=arr[min_itr-j];
					arr[min_itr-j] = temp;
				}
			}
			printf("Case #%lld:",itr);
			for_i(i,0,n)
				printf(" %lld",arr[i]);
			printf("\n");
		}
		else
		{
			printf("Case #%lld: IMPOSSIBLE\n",itr);
		}
	}
}
