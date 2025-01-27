#include <bits/stdc++.h>
using namespace std;
#define int long long int

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int32_t main() {
    int n,m;
    cin>>n>>m;
    
    DisjointSet ds(n);
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ds.unionBySize(a-1,b-1);
    }
    
    set<int> st;
    
    for(int i=0;i<n;i++){
        st.insert(ds.findUPar(i));
    }
    
    vector<int> temp(st.begin(),st.end());
    
    cout<<st.size()-1<<endl;
    for(int i=0;i<st.size()-1;i++){
        cout << temp[i]+1 << " " << temp[i+1]+1 << endl;
    }
    
    return 0;
}
