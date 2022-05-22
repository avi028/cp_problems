/*
*Problem Link:
https://www.codechef.com/JULY20B/problems/ADAKING
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
  int t,k;
  cin>>t;
  for_i(itr,0,t)
  {
    cin>>k;
    vector< vector<char> > v (8,vector<char>(8,'.'));
    v[0][0]='O';
    int r = k%8;
    int q=k/8;
    if (r==0)
    {
      if(q<8)
      {
        for_i(i,0,8)
        v[q][i]='X';
      }
    }
    else
    {
      if(q<7)
      {
        for_i(i,0,r+1)
          v[q+1][i]='X';
      }
      if(q>0)
      {
        for_i(i,r,8)
          v[q][i]='X';   
      } 
      else
        v[q][r]='X';   
    }
    
    for_i(i,0,8)
    {
      for_i(j,0,8)
        printf("%c",v[i][j]);
      printf("\n");
    }
//    cout<<endl;
  }
  return 0;
}
