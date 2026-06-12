//Link to this code: https://cses.fi/paste/994d5169c72acf50bf2265/

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
    ll n, target;
    cin >> n >> target;
    
    vll coins(n);
    for(ll i = 0; i < n; i++)   cin >> coins[i];
 
    vll dp(target + 1, 0);
    dp[0] = 1;
 
    for(ll i = 1; i <= target; i++) {
        for(ll j = 0; j < n; j++) {
            if(coins[j] <= i){
                dp[i] = 1LL*( dp[i] + dp[i - coins[j]] ) % mod;
            }
        }
        //cout << dp[i] << " ";
    }
 
    cout << dp[target];
    
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