#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n,m,q;
    cin>>n>>m>>q;
    
    vector<vector<int>> dist(n,vector<int>(n,-1));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j] == -1){
                dist[i][j] = LLONG_MAX;
            }
            
            if(i == j){
                dist[i][j] = 0;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        
        dist[a-1][b-1] = min(dist[a-1][b-1],c);
        dist[b-1][a-1] = min(dist[b-1][a-1],c);
    }
    
    vector<vector<int>> que(q);
    
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        que[i] = {a,b};
    }
    
    for(int inter=0;inter<n;inter++){
        for(int st=0;st<n;st++){
            for(int e=0;e<n;e++){
                if(dist[st][inter] < LLONG_MAX && dist[inter][e] < LLONG_MAX){
                    dist[st][e] = min(dist[st][e] , dist[st][inter] + dist[inter][e]);
                }
            }
        }
    }
    
    
    for(int i=0;i<q;i++){
        int x = que[i][0]-1;
        int y = que[i][1]-1;
        
        if(dist[x][y] == LLONG_MAX){
            cout<<-1<<endl;
        }
        else{
            cout<<dist[x][y]<<endl;
        }
    }
    
    return 0;
    
}
