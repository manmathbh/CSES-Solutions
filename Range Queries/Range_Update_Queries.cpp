/**
 * author: Manmath_H
 * created: 18.03.2026 15:18:31
 * Link to this code: https://cses.fi/paste/793034c02ca93d8afd4bf9/
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define mod 998244353
using u64 = unsigned long long;
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
//binary indexed tree
 
class BIT{
public:
    int n;
    vector<int> tree;
 
    BIT(int n){
        this->n = n;
        tree.resize(n+2, 0);
    }
 
    void add_update(int i, int delta){
        for(; i <= n; i += (i & -i))   tree[i] += delta;
    }
 
    void range_add_update(int l, int r, int val){
        add_update(l, val);
        add_update(r+1, -val);
    }
 
    int query(int idx){
        int sum = 0;
        for(; idx >0; idx -= (idx & -idx))   sum += tree[idx];
 
        return sum;
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    BIT bit(n);
 
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
 
        bit.range_add_update(i, i, x);
    }
 
    for(auto it : bit.tree) cerr << it << ' ';
 
    
    while(q--){
        int qry;
        cin >> qry;
 
        if(qry == 1){
            int l, r, u;
            cin >> l >> r >> u;
 
            bit.range_add_update(l, r, u);
        }
        else{
            int idx;
            cin >> idx;
 
            cout << bit.query(idx) << '\n';
        }
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