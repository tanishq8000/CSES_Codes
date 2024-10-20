#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
	int n;
	cin>>n;
	int arr[n];
	set<int> s;
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	    s.insert(arr[i]);
	}
	cout<<s.size()<<endl;
	return 0;
}
