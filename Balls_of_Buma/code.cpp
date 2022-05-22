/*
    problem : http://codeforces.com/problemset/problem/1267/B 
*/

#include <bits/stdc++.h>
using namespace std ;

int main()
{
    vector< pair<int,char> > inset;
    string in;
    while(cin>>in)
    {
        int n = in.length();
        int count;
        count=0;
        for(int i =0 ;i <n;i++)
        {
            if (in[i] == in[i+1])
            {
                count++;            
            }
            else
            {
                count++;
                inset.push_back(make_pair(count,in[i]));
                count=0;
            }
        }
        if (inset.size()%2==0)
        {    
            cout<<0<<endl;
        }
        else 
        {   
            n = inset.size();
            int i;
            for(i=0;i<n/2;i++)
            {
                if (!((inset[i].second == inset[n-1-i].second) && (inset[i].first+inset[n-1-i].first>=3)))
                {
                    cout<<0<<endl;
                    break;
                }
            }
            if (i==n/2)
            {
                if (inset[i].first>=2)
                {
                    cout<<inset[n/2].first+1<<endl;
                }        
                else
                {
                    cout<<0<<endl;
                }
            }
        }    
        // for (size_t i = 0; i < inset.size(); i++)
        // {
        //     cout<<inset[i].first<<inset[i].second<<endl;
        // }
        inset.clear();
    }
        
   return 0;
}