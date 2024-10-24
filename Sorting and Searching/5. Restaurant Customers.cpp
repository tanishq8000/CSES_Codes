#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n;
    cin>>n;
    vector<int> arr(n),dep(n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i] = a;
        dep[i] = b;
    }
    
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    
    
    int i=0,j=0;
    int cnt = 0,ans=0;
    
    while(i<n && j<n)
    {
        if(arr[i] < dep[j])
        {
            cnt++;
            ans = max(ans,cnt);
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
