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
	    for(int j=i+1;j<n;j++)
	    {
	        int k=j+1,l=n-1;
	        int tg = x - arr[i].first-arr[j].first;
	        
	        while(k<l)
	        {
	            int curr = arr[k].first+arr[l].first;
	            if(curr>tg)
	            {
	                l--;
	            }
	            else if(curr<tg)
	            {
	                k++;
	            }
	            else
	            {
	                cout<<arr[i].second<<" "<<arr[j].second<<" "<<arr[k].second<<" "<<arr[l].second<<endl;
	                return 0;
	            }
	        }
	    }
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
