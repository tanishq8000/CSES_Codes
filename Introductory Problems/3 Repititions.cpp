#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
	string s;
	cin>>s;
	
	int cnt = 1,maxLen = INT_MIN;
	char ch = s[0];
	
	for(int i=1;i<s.length();i++)
	{
	     if(s[i] == ch)
	     {
	         cnt++;
	     }
	     else
	     {
	         maxLen = max(maxLen,cnt);
	         cnt = 1;
	         ch = s[i];
	     }
	}
	
	maxLen = max(maxLen,cnt);
	
	cout<<maxLen<<endl;
	return 0;
}
