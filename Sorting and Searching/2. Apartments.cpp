#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n,m,k;
    cin>>n>>m>>k;
    
    int des[n],av[m];
    
    for(int i=0;i<n;i++)
    {
        cin>>des[i];
    }
    
    for(int i=0;i<m;i++)
    {
        cin>>av[i];
    }
    
    sort(des,des+n);
    sort(av,av+m);
    
    int i=0,j=0;
    int cnt = 0;
    
    while(i<n && j<m)
    {
        if((des[i]-k)<=av[j] && (des[i]+k) >= av[j])
        {
            cnt++;
            i++;
            j++;
        }
        else if(av[j] > des[i])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    
    cout<<cnt<<endl;
    
}
