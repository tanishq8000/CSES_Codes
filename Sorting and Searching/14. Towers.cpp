#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    multiset<int> s;
    
    for(int i=0;i<n;i++)
    {
        auto it = s.upper_bound(arr[i]);
        
        if(it == s.end())
        {
            s.insert(arr[i]);
        }
        else
        {
            s.erase(it);
            s.insert(arr[i]);
        }
    }
    
    cout<<s.size()<<endl;
}
