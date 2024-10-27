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
    
    int s1=0,s2=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        s1 += arr[i];
        if(s2 < s1)
        {
            s2 = s1;
        }
        if(s1<0)
        {
            s1=0;
        }
    }
    
    cout<<s2<<endl;
    return 0;
}
