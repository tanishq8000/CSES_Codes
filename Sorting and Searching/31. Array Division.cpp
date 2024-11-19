#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(ll* arr, ll N, ll K, ll mid)
{
    ll partitions = 1, runningSum = 0;
    for (int i = 0; i < N; i++) {
        runningSum += arr[i];
        if (runningSum > mid) {
            runningSum = arr[i];
            partitions += 1;
        }
    }
    return partitions <= K;
}

ll solve(ll* arr, ll N, ll K)
{
    ll low = *max_element(arr, arr + N),
    high = accumulate(arr, arr + N, 0LL);
    ll ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (isValid(arr, N, K, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<solve(arr,n,k)<<endl;
    return 0;
}
