#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    string s;
    cin>>s;
    
    vector<string> ans;
    sort(s.begin(),s.end());
    string temp = s;

    
    do{
        ans.push_back(temp);
    }while(next_permutation(temp.begin(),temp.end()));
    
    cout<<ans.size()<<endl;
    for(auto x:ans)
    {
        cout<<x<<endl;
    }
    
    return 0;
}
