/**
 * author: Manmath_H
 * created: 13.06.2026 09:46:57
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define pb push_back
typedef __int128 Int;
#define endl '\n'
#define INF (int)1e18
#define mod 998244353
using u64 = unsigned long long;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int MAX = 200005;
const int LOG = 20;

int UP[MAX][LOG];
int depth[MAX];

vvi adj;

//building UP and depth
void dfs(int u, int p, int d){
    UP[u][0] = p;
    depth[u] = d;

    for(int i = 1; i<LOG; i++){
        UP[u][i] = UP[UP[u][i-1]][i-1];
    }

    for(auto &v : adj[u]){
        if(v!= p){
            dfs(v, u, d+1);
        }
    }
}

//binary lifting lca
int get_lca(int u, int v){
    //assuming u has the more depth
    if(depth[u] < depth[v])     swap(u, v);

    //equalize depth
    int diff = depth[u]-depth[v];

    for(int i = LOG-1; i>=0; i--){
        if((diff>>i)&1)     u = UP[u][i];
    }

    if(u == v)  return u;

    for(int i = LOG-1; i>=0; i--){
        if(UP[u][i] != UP[v][i]){
            u = UP[u][i];
            v = UP[v][i];
        }
    }

    return UP[u][0];
}

void solve() {
    int n, q;
    cin >> n >> q;

    adj.resize(n+1);

    for(int u = 2; u <= n; u++){
        int v;
        cin >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 1, 0);

    for(int i = 0; i<q; i++){
        int u, v;
        cin >> u >> v;
        cout << get_lca(u, v) << "\n";
    }

}

int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  //cerr << "Code_by_Manmath_H: " << elapsed.count() * 1e-9 << " sec.\n";
  return 0;
}