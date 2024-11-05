#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int x,n;
    cin>>x>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    set<pair<int,int>> ranges;
    multiset<int> rangeLen;
    ranges.insert({0,x});
    rangeLen.insert(x);
    
    for(int i=0;i<n;i++)
    {
        int pos = arr[i];
        
        auto it = ranges.upper_bound({pos,0});
        it--;
        
        int s = it->first;
        int e = it->second;
        
        ranges.erase(it);
        
        rangeLen.erase(rangeLen.find(e-s));
        
        ranges.insert({s,pos});
        ranges.insert({pos,e});
        rangeLen.insert(pos-s);
        rangeLen.insert(e-pos);
        
        cout<<*rangeLen.rbegin()<<" ";
    }
    
    cout<<endl;
    return 0;
}
