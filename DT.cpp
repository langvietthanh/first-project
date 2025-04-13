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
map<int,int> Deg;
struct Edge{
    int u,v,w;
};
vector <Edge> E;
void input(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        E.push_back({u,v,w});
        Deg[u]++;
        Deg[v]++;
    }
}

void OpenFile() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}

void cal_deg(){
    for(auto x:Deg)cout<<x.second<<" ";
}

void mt_ke(){
    cout<<n<<endl;
    int a[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=(i==j?0:10000);
        }
    }
    for(auto x:E){
        a[x.u][x.v]=a[x.v][x.u]=x.w;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
        cout<<endl;
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
    vector<pii> edge;
    int m;
    for(int u=1;u<=n;u++){
        for(auto v:adj[u]){
            if(v>u)edge.push_back({u,v});
        }
    }
    m=sz(edge);
    int b[n+1][m+1]={0};
    for(int i=0;i<m;i++){
        b[edge[i].first][i+1]=b[edge[i].second][i+1]=1;
    }
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cout<<b[i][j]<<" ";
        cout<<endl;
    }
}

// void ds_canh(){
//     vector<pii> edge;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(a[i][j]!=10000&&a[i][j]!=0&&i<j)edge.push_back({i,j});
//         }
//     }
//     cout<<n<<" "<<sz(edge)<<endl;
//     for(auto x: edge){
//         cout<< x.first<<" "<<x.second<<" "<<a[x.first][x.second]<<endl;
//     }
// }

int main(){
    OpenFile();
    int t;
    cin>>t;
    input();
    if(t==1){
        cal_deg();
    }
    else {
        mt_ke();
    }
}