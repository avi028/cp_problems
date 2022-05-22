/*
*Problem Link:
http://codeforces.com/problemset/problem/999/B
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  int mid;
  string s;
  vector<int> d;
  while (cin>>n)
  {
    cin>>s;
    for (size_t i = 2; i <= n; i++)
      if(n%i == 0)
        d.push_back(i);     
    
    // for (size_t i = 0; i < d.size(); i++)
    // {
    //   cout<<d[i]<<endl;
    // }
    for (  size_t i = 0; i <d.size(); i++)
    {
      char c;
      mid = d[i]/2;
      for (size_t j = 0; j <mid; j++)
      {
        c = s[j];
        s[j] = s[d[i]-1-j];
        s[d[i]-1-j]=c;
      }
    }    
    d.clear();
    cout<<s<<endl;
  }
  return 0;
}