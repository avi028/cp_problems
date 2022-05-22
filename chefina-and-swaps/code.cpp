/*
*Problem Link:
https://www.codechef.com/JULY20B/problems/CHFNSWPS
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
#define debug(x) std::cout << #x <<x<< std::endl

//usable Functions
long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}
ll b_search(vector<ll> v , ll x){ll h,l,m;h=v.size()-1;l=0;while(l<=h){m=(l+h)/2;if(v[m]==x)return m;if(v[m]>x) h=m-1;else l=m+1;}return -1;}
void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}

// int main()
// {
//   ll t,n;
//   scanf("%lld",&t);
//   for_i(itr,0,t)
//   {
//     n=0;
//     scanf("%lld",&n);
//     vector<ll> a(n),b(n);
//     ll na,nb;
//     for_i(i,0,n)
//       scanf("%lld ",&a[i]);
//     for_i(i,0,n)
//       scanf("%lld ",&b[i]);
//       ll min1;
//     sort(a.begin(),a.end());
//     sort(b.begin(),b.end());
//     min1 = a[0]<b[0]?a[0]:b[0];
//      na=nb=n; 
//      for_i(i,0,n)
//      {
//        ll index = b_search(b,a[i]); 
//        if (index!=-1)
//        {
//          a.erase(a.begin()+i);
//          i--;
//          b.erase(b.begin()+index);
//          n--;
//        }
//      } 
//     if(n==0)
//       printf("0\n");
//     else if(n%2==0)
//     {
//         na=nb=n;
//         ll x,y;
//         x = a[0];
//         for_i(i,1,n)
//           x=x^a[i];
//         y = b[0];
//         for_i(i,1,n)
//           y=y^b[i];
//         if(y==0 && x==0)
//         {
//             vector<ll> a1,b1;
//             for_i(i,1,na)
//             {
//               if(a[i]==a[i-1])
//               {
//                   a1.push_back(a[i-1]);
//                   i++;
//   //                a.erase(a.begin()+i-1);
//   //               na--;
//               }
//             }
//             for_i(i,1,nb)
//             {
//               if(b[i]==b[i-1])
//               {
//                   b1.push_back(b[i-1]);
//                   i++;
// //                   b.erase(b.begin()+i-1);
// //                  nb--;
//               }
//             }
//             // cout<<"ans out\n";
//             // print_v(a);
//             // print_v(b);
//             // print_v(a1);
//             // print_v(b1);
//             ll ans=0;
//             ll ia=0,ib=0;
//             na=a1.size();
//             nb=b1.size();
//             ll count=na;
//             ll m = a1[0]<b1[0]?a1[0]:b1[0];
//             if(min1<m)
//             {
//               ans=0;
//               m=min1;
//             }
//             else
//             {
//               if(m==a1[0])
//                 ia++;
//               else
//                 ib++;
//               count--;
//               ans=m;
//             }
//             ll temp;
//             while(ia<na && ib<nb && count>0)
//             { 
//               if(a1[ia]<b1[ib])
//               {
//                 temp = a1[ia];
//                 ia++;
//               } 
//               else
//               {
//                 temp = b1[ib];
//                 ib++;
//               }
//               if(temp<(2*m))
//                 ans+=temp;
//               else
//                 ans+=(2*m);
//               count--;
//             }
//             printf("%lld\n",ans);
//         }
//         else
//           printf("-1\n");
//     }
//     else
//       printf("-1\n");
//    }
//   return 0;
// }


/*solution 2 */

int main()
{
  ll t,n,x,ans,in;
  vector<ll> a,b;
  map<ll,ll> m;
  ll min1;
  bool flag;
  
  scanf("%lld",&t);
  for_i(itr,0,t)
  {
    n=0;
    in=0;
    x=0;
    ans=0;
    flag=false;
    a.clear();
    b.clear();
    m.clear();
    scanf("%lld",&n);
    for_i(i,0,n)
    {
      scanf("%lld ",&in);
      m[in]+=1;
    }
    for_i(i,0,n)
    {
      scanf("%lld ",&in);
      m[in]-=1;
    }
    min1=MOD;
    for_map(i,m)
    {
      in = i->second;
      if(abs(in)%2!=0)
        flag=true;
      else
      {
        in/=2;
        x = i->first;
        min1 = min(min1,x);
        if(in>0)
        {
          while(in--)
            a.push_back(x);
        }        
        else
        {
          in=abs(in);
          while(in--)
            b.push_back(x);
        }
      }
    }
    reverse(b.begin(),b.end());
    // print_v(a);
    // print_v(b);
    if(flag)
      ans=-1;
    else
    {
      ans=0;
      n=a.size();
      for_i(i,0,n)
        ans+= min(2*min1,min(a[i],b[i]));

    }
    printf("%lld\n",ans);
  }
  return 0;
}
