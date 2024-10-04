#include <bits/stdc++.h>
using namespace std;

long calculateWays(int K) {
    long totalWays = ((long) K * K * (K * K - 1)) / 2;
    long attackingWays = 4 * (K - 1) * (K - 2);
    long ans = totalWays - attackingWays;
    return ans;
}

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<calculateWays(i)<<endl;
    }
    return 0;
}
