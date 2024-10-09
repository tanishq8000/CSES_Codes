#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int tst;
    cin>>tst;
    while(tst--)
    {
        int a,b;
        cin>>a>>b;
        
        if ((2 * a - b) % 3 || (2 * a - b) < 0|| (2 * b  - a) % 3 || (2 * b - a) < 0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
