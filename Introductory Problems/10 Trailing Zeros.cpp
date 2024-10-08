#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n;
    cin>>n;
        
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    cout<<count<<endl;
    
    return 0;
}
