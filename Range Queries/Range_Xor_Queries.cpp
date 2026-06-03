/**
 * author: Manmath_H
 * created: 15.03.2026 15:11:30
 * Link to this code: https://cses.fi/paste/6f4630c6cb7e360dfcb9ee/
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
 
    vector<int> pfxXor(n+1);
 
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        pfxXor[i] = pfxXor[i-1]^x;
    }
 
    while(q--){
        int l, r;
        cin >> l >> r;
 
        cout << (pfxXor[r]^pfxXor[l-1]) << '\n';
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