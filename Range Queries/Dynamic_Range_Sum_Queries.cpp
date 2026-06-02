/**
 * author: Manmath_H
 * created: 15.03.2026 17:28:48
 * Link to this code: https://cses.fi/paste/1edccdd4b7dfc8b5fcc025/
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define mod 998244353
using u64 = unsigned long long;
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
class segmentTree{
public:
 
    vector<int> v, seg;
 
    segmentTree(int n){
        v.resize(n+1);
        seg.resize(4*n + 1);
    }
 
    void build(int idx, int lo, int hi){
        //base case
        if(lo == hi){
            seg[idx] = v[lo];
            return;
        }
 
        int mid = lo + (hi-lo)/2;
        build(2*idx + 1, lo, mid);
        build(2*idx + 2, mid+1, hi);
 
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
 
    void update(int idx, int lo, int hi, int pos, int val){
        //base case
        if(lo == hi){
            seg[idx] = val;
            v[lo] = val;
            return;
        }
 
        int mid = lo + (hi-lo)/2;
        if(pos <= mid){
            update(2*idx + 1, lo, mid, pos, val);
        }
        else   update(2*idx + 2, mid+1, hi, pos, val);
 
        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }
 
    int query(int idx, int lo,  int hi, int l, int r){
        //complate overlap
        if(lo >= l && hi <= r)   return seg[idx];
        //no overlap
        if(lo > r || hi < l)   return 0;
        //partial overlap
        int mid = lo + (hi-lo)/2;
        int left = query(2*idx + 1, lo, mid, l, r);
        int right = query(2*idx + 2, mid+1, hi, l, r);
 
        return left+right;
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    segmentTree segT(n);
    segT.v.clear();
 
    for(int i = 0; i<n; i++){
        cin >> segT.v[i];
    }
 
    segT.build(0, 0, n-1);
 
    while(q--){
        int qr;  cin >> qr;
        if(qr == 1){
            int k, u;
            cin >> k >> u;
            k--;
 
            segT.update(0, 0, n-1, k, u);
        }
        else{
            int a, b;
            cin >> a >> b;
            a--, b--;
 
            cout << segT.query(0, 0, n-1, a, b) << '\n';
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