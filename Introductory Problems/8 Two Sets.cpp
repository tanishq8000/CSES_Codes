#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n;
    cin>>n;
    int sum = (n*(n+1))/2;
    
    if(sum%2 == 1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        vector<int> a,b;
        cout<<"YES"<<endl;
        if(n%2 == 0)
        {
            for(int i=1;i<=n/2;i++)
            {
                if(i%2 == 1)
                {
                    a.push_back(i);
                    a.push_back(n-i+1);
                }
                else
                {
                    b.push_back(i);
                    b.push_back(n-i+1);
                }
            }
        }
        else
        {
            a.push_back(1);
            a.push_back(2);
            b.push_back(3);
            
            int l=4,r=n;
            bool flag = true;
            
            while(l<r)
            {
                if(flag)
                {
                    a.push_back(l);
                    a.push_back(r);
                }
                else
                {
                    b.push_back(l);
                    b.push_back(r);
                }
                
                flag = (flag==true) ? false : true;
                l++;
                r--;
            }
        }
        
        cout<<a.size()<<endl;
        for(auto x:a)
        {
            cout<<x<<" ";
        }
        cout<<endl;
            
        cout<<b.size()<<endl;
        for(auto x:b)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
