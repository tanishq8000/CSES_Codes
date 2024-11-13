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
    
    stack<int> st;
    
    vector<int> ans(n);
    
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            ans[i]=0;
        }
        else
        {
            while(!st.empty() &&arr[st.top()-1] >= arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[i]=0;
            }
            else
            {
                ans[i] = st.top();
            }
        }
        st.push(i+1);
    }
    
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
