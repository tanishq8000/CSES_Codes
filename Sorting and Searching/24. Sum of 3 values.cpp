#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
	int n,x;
	cin>>n>>x;
	vector<pair<int,int>> arr(n);
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i].first;
	    arr[i].second = i+1;
	}
	
	sort(arr.begin(),arr.end());
	
	for(int i=0;i<n;i++)
	{
	    auto f = arr[i];
	    int j=i+1,k=n-1,tg=x-f.first;
	    
	    
	    while(j<k)
	    {
	        int val = arr[j].first+arr[k].first;
	        if(val>tg)
	        {
	            k--;
	        }
	        else if(val<tg)
	        {
	            j++;
	        }
	        else
	        {
	            cout<<f.second<<" "<<arr[j].second<<" "<<arr[k].second<<endl;
	            return 0;
	        }
	    }
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
