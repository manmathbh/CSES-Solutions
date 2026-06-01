/**
 * author: Manmath_H
 * Link to this code: https://cses.fi/paste/c34cfbe790f82070fcbe8b/
 * created: 15.03.2026 16:47:33
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define mod 998244353
using u64 = unsigned long long;
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
//vector<int> v(200001), seg(4*200001);
 
class segmentTree{
public:
 
    vector<int> v, seg;
    segmentTree(int n){
        v.resize(n+1);
        seg.resize(4*n + 1);
    }
 
    void build(int idx, int lo, int hi){
        /// base case
        if(lo == hi){
            seg[idx] = v[lo];
            return;
        }
 
        int mid = lo + (hi-lo)/2;
        build(2*idx + 1, lo, mid);
        build(2*idx+2, mid+1, hi);
 
        seg[idx] = min(seg[2*idx + 1], seg[2*idx + 2]);
    }
 
    int query(int idx, int lo,  int hi, int l, int r){
        //base case
        if(lo >= l && hi <= r)    return seg[idx];
        if(lo > r || hi < l)    return INF;
 
        //else boundry overlappin
        int mid = lo + (hi - lo)/2;
        int left = query(2*idx+1, lo, mid, l, r);
        int right = query(2*idx + 2, mid+1, hi, l, r);
 
        return min(left, right);
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
    segmentTree segT(n);
    //segT.v.clear();
 
    for(int i = 0; i<n; i++){
        cin >> segT.v[i];
    }
 
    segT.build(0, 0, n-1);  // idx, 0, n-1
 
    while(q--){
        int l, r;
        cin >> l >> r;
 
        l--, r--;
 
        cout << segT.query(0, 0, n-1, l, r) << '\n';  // idx, lo, hi, l, r
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