#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n;
    cin>>n;
    
    queue<int> q;
    
    for(int i=0;i<n;i++)
    {
        q.push(i+1);
    }
    
    while(!q.empty())
    {
        int first = q.front();
        q.pop();
        q.push(first);
        
        int second = q.front();
        q.pop();
        
        cout<<second<<" ";
    }
    cout<<endl;
    return 0;
}
