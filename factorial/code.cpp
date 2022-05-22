/*
*Problem Link:
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/tutorial/
*/

#include <bits/stdc++.h>
#define MOD (1000000000+7)
#define ll long long int
using namespace std;

ll ar[100005];
int main()
{

  ll t;
  ll x;

  ar[0]=1;
  ar[1]=1;
  ar[2]=2;

  for (size_t i = 3; i < 100001; i++)
  {
    ar[i] = ((ar[i-1])%MOD*i)%MOD;
  }

  cin >>t;
  
  for (size_t itr = 0; itr < t; itr++)
  {
    cin>>x;
    cout<<ar[x]<<endl;
  }
  
  return 0;
}
