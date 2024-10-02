#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
	int n;
	cin>>n;
	
	if(n == 1)
	{
	    cout<<1<<endl;
	}
	else if(n>1 && n<4)
	{
	    cout<<"NO SOLUTION"<<endl;
	}
	else
	{
	    for(int i=2;i<=n;i+=2)
	    {
	        cout<<i<<" ";
	    }
	    for(int i=1;i<=n;i+=2)
	    {
	        cout<<i<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}
