/*
*Problem:
  Given a string that represents a base X number, convert it to equivalent string in base Y,
  2 ≤ X, Y ≤ 36. For example: “FF” in base X = 16 (Hexadecimal) is “255” in base Y1 = 10
  (Decimal) and “11111111” in base Y2 = 2 (binary).

*/
#include <bits/stdc++.h>
using namespace std;
int main(){ int x1=1,i=0,x,y,d=0;
  string s;
  scanf("%d %s %d",&x,&s[0],&y);
  for(i=s1.size()-1;i>=0;i--){d+= (((s[i]-48>=0) && (s[i]-48<10))?(s[i]-48):((s[i]-65)+10) )*x1;
  x1*=x;}
  while(d>0){s[++i]=(d%y<10)?(d%y)+48:(d%y)+65;
  d/=y;}
  s[++i]='\0';
  reverse(s.begin(),s.end());
  cout<<s1<<endl;
  return 0;}