#include <bits/stdc++.h>
using namespace std;
#define int long long int

int mypow(int x,unsigned int y)
{
    int res = 1;
    while(y>0)
    {
        if(y&1)
        {
            res = res*x;
        }
        y = y>>1;
        x = x*x;
    }
    return res;
}

int32_t main() {
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        
        int c = 1;
        
        for(int p=9 ; ; n-=p , c++, p = 9 * mypow(10,c-1) *c)
        {
            if(n-p <= 0)
            {
                break;
            }
        }
        
        n--;
        
        int x = n/c;
        int y = n%c;
        int ans = mypow(10,c-1) + x;
        
        string temp = to_string(ans);
        
        cout<<temp[y]<<endl;
    }
    return 0;
}
