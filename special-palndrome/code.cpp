/*
*Problem Link:
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/special-palindrome-3/description/
*/


#include <bits/stdc++.h>
using namespace std;
//Defines
#define MOD 1000000007
#define ll long long int
#define for_i(x,i,l) for(size_t x = i; x<l;x++) 
#define for_i_neg(x,i,l) for(int x = l; x>=i;x--) 

#define debug(x) std::cout << #x <<x<< std::endl
//usable Functions
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}

void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}

int main()
{
  int t;  
  cin>>t;
  while(t--)
  {
    char c;
    string s;
    int n;
  
    cin>>c;
    cin>>s;
    n=s.size();
    vector<vector<ll> > v(n,vector<ll>(n,0));
    for_i(i,0,n){
      v[i][i]=1;
    }

    for_i(gap,2,n+1)
    {
      for_i(i,0,n-gap+1)
      {
        int j=gap+i-1;
        if(s[i]==s[j])
           v[i][j]= gap==2?2:v[i+1][j-1]+2; 
        else
          v[i][j]=max(v[i+1][j],v[i][j-1]);
      }
    }
    print_v(v[0]);
  }
  return 0;
}
