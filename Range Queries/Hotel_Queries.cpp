/**
 * author: Manmath_H
 * created: 21.03.2026 16:55:44
 * Link to this code: https://cses.fi/paste/fcd880c57e25f7eefddddf/
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define mod 998244353
using u64 = unsigned long long;
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
class SegmentTree{
public:
    vector<int> v, seg;
 
    SegmentTree(int n){
        v.resize(n);
        seg.resize(4*n + 1);
    }
 
    void build(int idx, int lo, int hi){
        // base case
        if(lo == hi){
            seg[idx] = v[lo];
            return;
        }
        
        int mid = lo + (hi - lo)/2;
        build(2*idx + 1, lo, mid);
        build(2*idx + 2, mid+1, hi);
 
        seg[idx] = max(seg[2*idx + 1], seg[2*idx + 2]);
    }
 
    void update(){
 
    }
 
    int query(int idx, int lo, int hi, int x){
 
        if(seg[idx] < x)  return -1;
 
        //base case
        if(lo == hi){
            if(seg[idx] >= x){
                seg[idx] -= x;
                v[lo] -= x;
                return lo;
 
            }
            else    return -1;
        }
 
        int mid = lo + (hi - lo)/2;
        int ans = -1;
        if(seg[2*idx +1] >= x){
            ans = query(2*idx +1, lo, mid, x);
        }
        else   ans = query(2*idx +2 , mid+1, hi, x);
 
        seg[idx] = max(seg[2*idx + 1], seg[2*idx + 2]);
        return ans;
    }
 
};
 
void solve() {
    int n, m; 
    cin >> n >> m;
 
    SegmentTree segT(n);
 
    for(int i = 0; i<n; i++){
        cin >> segT.v[i];
    }
 
    segT.build(0, 0, n-1);  //(idx, lo, hi)
 
    while(m--){
        int r;
        cin >> r;
 
        cout << segT.query(0, 0, n-1, r) +1<< " ";
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