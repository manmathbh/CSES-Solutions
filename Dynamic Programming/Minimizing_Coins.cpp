//Link to this code: https://cses.fi/paste/a0c12a58faaaeefabf146c/
#include <bits/stdc++.h>
using namespace std;
 
#define ld long double
#define ll long long
#define f(i, m, n) for (int i = m; i <= n; i++)
#define rf(i, m, n) for (int i = m; i >= n; i--)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n)-1; i >= 0; --i)
#define mod 1000000007
#define MOD 998244353
constexpr ll INF = 4e18;
 
using vi = vector<int>;
using vll = vector<ll>;
 
///////////////////////////////////////////////////////////////////////////////////////////
 
 
void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for(ll i = 0; i<n; i++)     cin >> coins[i];
    
    //ll dp[x+1] = {INF};
    vll dp(x+1, INF);
    dp[0] = 0;
 
    for(ll i = 1; i<=x; i++) {
        for(ll j = 0; j < n; j++){
            if(coins[j] <= i){
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
 
        }
    }
 
    if(dp[x] >= INF)    cout << -1;
    else    cout << dp[x];
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // ll t;
    // cin >> t;
 
   solve();
 
    // while (t--) {
    //     solve();
    // }
 
    return 0;
}