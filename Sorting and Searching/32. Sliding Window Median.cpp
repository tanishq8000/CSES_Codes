#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	
	multiset<int> low,up;
	
	int l=0,r=0;
	
	while(r<n)
	{
	    if(!up.empty() && *up.begin()<=arr[r])
	    {
	        up.insert(arr[r]);
	    }
	    else
	    {
	        low.insert(arr[r]);
	    }
	    
	    
	    if(up.size() > low.size())
	    {
	        low.insert(*up.begin());
	        up.erase(up.begin());
	    }
	    
	    if(up.size()+1 < low.size())
	    {
	        up.insert(*low.rbegin());
	        low.erase(prev(low.end()));
	    }
	    
	    if(r >= k-1)
	    {
	        cout<<*low.rbegin()<<" ";
	        
	        if(!low.empty() && low.find(arr[l])!=low.end())
	        {
	            low.erase(low.find(arr[l]));
	        }
	        else if(!up.empty() && up.find(arr[l])!=up.end())
	        {
	            up.erase(up.find(arr[l]));
	        }
	        l++;
	    }
	    
	    r++;
	}
	
	cout<<endl;
	return 0;
}
