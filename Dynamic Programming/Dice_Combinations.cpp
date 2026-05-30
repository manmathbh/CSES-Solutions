//Link to this code: https://cses.fi/paste/55446ad99eb2109abf134a/

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
 
using vi = vector<int>;
using vll = vector<ll>;
 
///////////////////////////////////////////////////////////////////////////////////////////
 
 
void solve() {
    ll n;
    cin >> n;
    ll dp[n+1] = {0};
    dp[0] = 1;
 
    for(ll i = 1; i<=n; i++) {
        dp[i] = 0;
        for(ll j = 1; j<= 6; j++){
            if(i >= j){
                dp[i] = (dp[i] + dp[i-j])%mod;
            }
            else    break;
        }
    }
 
    cout << dp[n];
    
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