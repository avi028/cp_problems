  /*
  *Problem Link:
  https://www.hackerearth.com/challenges/competitive/july-easy-20/algorithm/kshitiz-and-matrix-7ddc9719/
  */


  #include <bits/stdc++.h>
  using namespace std;
  //Defines
  #define inf 1000000009
  #define MOD 1000000007
  #define ll long long int
  #define for_i(x,i,l) for(size_t x = i; x<l;x++) 
  #define for_i_neg(x,i,l) for(int x = l; x>=i;x--) 
  #define mp(x,y) make_pair(x,y)
  #define debug(x) std::cout << #x <<x<< std::endl
  //usable Functions
  long long int power(long long int a,long long int b ){long long int x, result =1;x=a;while(b>0){if(b&1)result=(result*x)%MOD;x=(x*x)%MOD;b/=2;}return result;}

  void print_v(vector<ll> v){for_i(i,0,v.size()) cout<<v[i]<<'\t';cout<<endl;}

  int main()
  {
    ll t,n,m;
    scanf("%lld",&t);
    for_i(itr,0,t)
    {
      ll a;
      scanf("%lld %lld",&n,&m);
      ll mn=inf;
      ll mx=0;
      vector< vector<ll> > v(n,vector<ll>(m));
      vector<bool> r(n,0);
      vector<bool> c(m,0);
      for_i(i,0,n)
        for_i(j,0,m)
        {
          scanf("%lld",&a);
          v[i][j]=a;
          if(a>mx)
            mx=a;
          if (a<mn)
            mn=a;
        }
      for_i(i,0,n)
        for_i(j,0,m)
        {
          if (v[i][j]==mx || v[i][j]==mn)
            r[i]=c[j]=1;
        }
      ll rc,cc;
      rc=cc=0; 
      for_i(i,0,n)
      {
        if(r[i]==1)
          rc++;
      }
     for_i(i,0,m) 
      {
        if(c[i]==1)
          cc++;  
      }
      ll ans = n*m - (rc*m + cc*(n-rc));
      printf("%lld\n",ans);
    }
    return 0;
  }
