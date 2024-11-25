#include <bits/stdc++.h>
using namespace std;
#define int long long int

void med(int n,int k,vector<int> &arr)
{
    multiset<int> low,up;
    vector<int> ans;
	
	int l=0,r=0;
	
	int lsum=0,rsum=0;
	
	while(r<n)
	{
	    if(!up.empty() && *up.begin()<=arr[r])
	    {
	        rsum += arr[r];
	        up.insert(arr[r]);
	    }
	    else
	    {
	        lsum += arr[r];
	        low.insert(arr[r]);
	    }
	    
	    
	    if(up.size() > low.size())
	    {
	        low.insert(*up.begin());
	        lsum += *up.begin();
	        rsum -= *up.begin();
	        up.erase(up.begin());
	        
	    }
	    
	    if(up.size()+1 < low.size())
	    {
	        up.insert(*low.rbegin());
	        rsum += *low.rbegin();
	        lsum -= *low.rbegin();
	        low.erase(prev(low.end()));
	    }
	    
	    if(r >= k-1)
	    {
	        int med = *low.rbegin();
	        int sz1 = low.size();
	        int sz2 = up.size();
	        
	        cout<<(sz1 * med - lsum) + (rsum - med * sz2)<<" ";
	        
	        if(!low.empty() && low.find(arr[l])!=low.end())
	        {
	            low.erase(low.find(arr[l]));
	            lsum -= arr[l];
	        }
	        else if(!up.empty() && up.find(arr[l])!=up.end())
	        {
	            up.erase(up.find(arr[l]));
	            rsum -= arr[l];
	        }
	        l++;
	    }
	    
	    r++;
	}
}

int32_t main() {
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	
	med(n,k,arr);
	
	cout<<endl;
	return 0;
}
