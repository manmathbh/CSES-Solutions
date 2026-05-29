/**
 * author: Manmath_H
 * created: 29.05.2026 08:34:30
 * Link to this code: https://cses.fi/paste/52c2748d860bbe861089d89/
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
 
//KMP algo
vector<int> PI(const string &s){
  int n = s.size();
  vector<int> pi(n);
 
  for(int i = 1, j = 0; i <n; i++){
    while(j > 0 && s[i]!=s[j])  j = pi[j-1];
    if(s[i] == s[j])  j++;
    pi[i] = j;
  }
 
  return pi;
}
 
void solve() {
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
 
    if(m > n){
      cout << 0;
      return;
    }
 
    int cnt = 0;
    string st = p + '#' + s;
    vector<int> pi = PI(st);
 
    for(auto &it : pi)  cnt += (it == m);
 
    cout << cnt;
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