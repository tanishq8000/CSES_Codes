#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int mod = 1e9+7;
    int n;
    cin>>n;
    
    int p = 1;
    
    for(int i=0;i<n;i++)
    {
        p = (p*2)%mod;
    }
    cout<<p%mod<<endl;
    return 0;
}
