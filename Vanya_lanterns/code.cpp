/*
*Problem Link:
http://codeforces.com/problemset/problem/492/B
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int n,l;
  vector<long long int> in;
  long long int x,ans_index;
  long double ans,temp_r ;
  while(cin>>n>>l)
  {
    for (size_t i = 0; i < n; i++)
    {
      cin>>x;
      in.push_back(x);
    }
    sort(in.begin(),in.end());
    ans = (long double)(in[0]-0);
    for (size_t i = 0; i < n-1; i++)
    {
      temp_r = ((long double)(in[i+1]-in[i]))/2;
      ans = max(ans,temp_r);
    }
    temp_r = (long double)(l - in[n-1]);
    ans = max(ans,temp_r);
    printf("%.10Lf\n",ans);
    in.clear();
  }
  return 0;
}
