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
set<int> adj[1005];

void input(){
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
}

bool vst[1005];

void Dfs(int u){
    vst[u]=true;
    for(auto v:adj[u]){
        if(!vst[v]){
            Dfs(v);
        }
    }
}

bool ktlt(){
    Dfs(1);
    for(int i=1;i<=n;i++)if(!vst[i])return false;
    return true;
}
int check1(map<int,int> D){
    int cnt=0;
    for(auto x:D){
        if(x.second%2!=0){
            cnt++;
        }
    }
    if(cnt==0)return 1;
    else if(cnt<=2)return 2;
    else return 0;
}

void xdct(){
    cin>>n>>m;
    input();
    map<int,int> D;
    for(int i=1;i<=n;i++){
        for(auto x:adj[i]){
            D[i]++;
        }
    }
    if(!ktlt()){
        cout<<0;
        return;
    }
    if(check1(D)==2)cout<<2;
    else if(check1(D)==1)cout<<1;
    else cout<<0;
}

void tdd(){
    int start;
    cin>>n>>m;
    cin>>start;
    input();
    stack<int> st;
    st.push(start);
    vector<int> path;
    while(!st.empty()){
        int top=st.top();
        if(adj[top].size()>0){
            int Adj=*(adj[top].begin());
            st.push(Adj);
            adj[top].erase(Adj);
            adj[Adj].erase(top);
        }
        else{
            st.pop();
            path.push_back(top);
        }
    }
    reverse(path.begin(),path.end());
    for(auto x:path)cout<<x<<" ";
}

int main(){
    int t;
    cin>>t;
    if(t==1){
        xdct();
    }
    else {
        tdd();
    }
}