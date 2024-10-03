#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int tst;
    cin>>tst;
    while(tst--)
    {
        int y,x;
        cin>>y>>x;
        
        if(y>x)
        {
            int area = (y-1)*(y-1);
            
            if(y%2 == 1)
            {
                area += x;
            }
            else
            {
                area += (2*y-x);
            }
            
            cout<<area<<endl;
        }
        else
        {
            int area = (x-1)*(x-1);
            
            if(x%2 == 0)
            {
                area += y;
            }
            else
            {
                area += (2*x-y);
            }
            cout<<area<<endl;
        }
    }
    return 0;
}
