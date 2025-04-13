#include <bits/stdc++.h> 
using namespace std; 
using ll=long long;
const int maxn=100005;
const long long INF=1e18;
const ll MOD=1e9+7;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) x.size()
#define rvs(a) reverse(a.begin(),a.end())
#define mst_bool(x) memset(x,false,sizeof(x))
#define mst_int(x) memset(x,0,sizeof(x))
#define fe(x,a) for(auto x:a)
#define Fe(x,a) for(auto &x:a)
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
int n,m;
set<int> adj[105];

void input(){
    cin>>n;
    for(int u=1;u<=n;u++){
        int k;
        cin>>k;
        while(k--){
            int v;
            cin>>v;
            adj[u].insert(v);
            adj[v].insert(u);
        }  
    }
}

void OpenFile() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}

void cal_deg(){
    for(int i=1;i<=n;i++)cout<<adj[i].size()<<" ";
    cout<<endl;
}

void mt_ke(){
    int a[n+1][n+1]={0};
    for(int i=1;i<=n;i++){
        for(auto j:adj[i]){
            a[i][j]=1;
        }
    }
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";cout<<endl;
    }
}

void ds_ke(){
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cout<<adj[i].size()<<" ";
        for(auto x:adj[i])cout<<x<<" ";cout<<endl;
    }
}

void mt_lt(){
    int b[n+1][m+1]={0};
    int k=1;
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        for(auto j:adj[i]){
            if(j>i){
                b[i][k]=b[j][k]=1;
                k++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cout<<b[i][j]<<" ";cout<<endl;
    }
}

void ds_canh(){
    vector<pii> edge;
    for(int i=1;i<=n;i++){
        for(auto v:adj[i]){
            if(v>i){
                edge.push_back({i,v});
            }
        }
    }
    cout<<n<<" "<<sz(edge)<<endl;
    for(auto x: edge){
        cout<< x.first<<" "<<x.second<<endl;
    }
}

int main(){
    OpenFile();
    int t;
    cin>>t;
    input();
    if(t==1){
        cal_deg();
    }
    else {
        ds_canh();
    }
}