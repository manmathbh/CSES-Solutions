/**
 * author: Manmath_H
 * created: 16.03.2026 14:28:21
 * Link to this code: https://cses.fi/paste/83a40d5c3dc0fc9efce677/
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
 
    //build segment tree
    void build(int idx, int lo, int hi){
        //base case
        if(lo == hi){
            seg[idx] = v[lo];
            return;
        }
 
        int mid = lo + (hi-lo)/2;
        build(2*idx + 1, lo, mid);
        build(2*idx + 2, mid+1, hi);
 
        seg[idx] = min(seg[2*idx + 1], seg[2*idx + 2]);
    }
 
    void update(int idx, int lo, int hi, int pos, int val){
        //base case
        if(lo == hi){   //mid == lo == hi
            seg[idx] = val;
            v[lo] = val;
            return;
        }
 
        int mid = lo + (hi-lo)/2;
        if(pos <= mid){
            update(2*idx + 1, lo, mid, pos, val);
        }
        else    update(2*idx + 2, mid+1, hi, pos, val);
 
        seg[idx] = min(seg[2*idx + 1], seg[2*idx + 2]);
    }
 
    int query(int idx, int lo, int hi, int l, int r){
        //base case
        //complete overlap
        if(lo >= l && hi <= r)  return seg[idx];
        //no overlap
        if(lo > r || hi < l)  return INT_MAX;
        //partial overlap
        int mid = lo + (hi-lo)/2;
        int left = query(2*idx +1, lo, mid, l, r);
        int right = query(2*idx +2, mid+1, hi, l, r);
 
        return min(left, right);
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    segmentTree segT(n);
    for(int i = 0; i<n; i++){
        cin >> segT.v[i];
    }
 
    segT.build(0, 0, n-1);
 
    while(q--){
        int qry;
        cin >> qry;
 
        if(qry == 1){
            int k, u;
            cin >> k >> u;
            k--;
            segT.update(0, 0, n-1, k, u);
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
 
            cout << segT.query(0, 0, n-1, l, r) << '\n';
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