#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
	string s;
	cin>>s;
	
	int n = s.length();
	
	vector<int> mp(26,0);
	
	for(auto x:s)
	{
	    mp[x-'A'] += 1;
	}
	
	int oddFreq = 0;
	
	for(int i=0;i<26;i++)
	{
	    if(mp[i] %2 == 1)
	    {
	        oddFreq++;
	    }
	}
	
	if(oddFreq>1)
	{
	    cout<<"NO SOLUTION"<<endl;
	    return 0;
	}
	
	string ans(n,' ');
	
	int l = 0,r=n-1;
	
	for(int i=0;i<n;i++)
	{
	    if(mp[s[i]-'A'] % 2 == 1)
	    {
	        ans[n/2] = s[i];
	        mp[s[i]-'A']--;
	    }
	    
	    while(mp[s[i]-'A'] > 0)
	    {
	        ans[l++] = ans[r--] = s[i];
	        mp[s[i]-'A']-=2;
	    }
	}
	
	cout<<ans<<endl;
	return 0;
}
