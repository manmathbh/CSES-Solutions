/**
 * author: Manmath_H
 * Link to this code: https://cses.fi/paste/be1159d6ebc4b81efcb863/
 * created: 15.03.2026 14:35:21
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
 
    vector<int> x(n+1);
 
    for(int i = 1; i<=n; i++){
        cin >> x[i];
        x[i] += x[i-1];
    }
 
    while(q--){
        int a, b;
        cin >> a >> b;
 
        cout << x[b] - x[a-1] << '\n';
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