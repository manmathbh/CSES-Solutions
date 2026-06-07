/**
 * author: Manmath_H
 * created: 20.03.2026 17:42:56
 * Link to this code: https://cses.fi/paste/26203a3b045e0547fdadbc/
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define mod 998244353
using u64 = unsigned long long;
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    vector<vector<int>> pfx(n+1, vector<int>(n+1,0));
 
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= n; j++){
            char x;
            cin >> x;
 
            pfx[i][j] = (x=='*') + pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];
        }
    }
 
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
 
        cout << pfx[x2][y2] - pfx[x2][y1-1] - pfx[x1-1][y2] + pfx[x1-1][y1-1] << '\n';
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