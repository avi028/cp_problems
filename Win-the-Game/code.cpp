/*
*Problem Link:
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/win-the-game/description/
*/

#include <bits/stdc++.h>

#define MOD 1000000000+7
#define ll long long int
using namespace std;

int main()
{
  int t;
  int r,g;
  long double ans ;
  long double total;
  cin>>t;
  for (size_t itr = 0; itr < t; itr++)
  {
    ans=0.0;
    total = 0.0;
    cin >>r>>g;
    if (g==0 || r ==0) 
      ans = 1.00000000;
    else if (g == 1 && r ==1)
      ans = 0.500000;
    else
    { 
      total = (long double)((r+g)*1.0);
      ans = (long double)((r*1.0)/total);
      long double t = ans;
      for (size_t i = 1; i <=g; i++)
      {
         t =(t *(long double)((g-i+1)/(total-i)) \
        * (long double)((g-i)/(total-i-1)) ); 
        ans = ans+t;
        i++;  
      }
    }
    printf("%.6Lf\n",ans);
  }
  return 0;
}