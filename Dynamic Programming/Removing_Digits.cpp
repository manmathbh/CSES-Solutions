#include <bits/stdc++.h>
using namespace std;
 
#define ld long double
#define ll long long
#define f(i, m, n) for (ll i = m; i <= n; i++)
#define rf(i, m, n) for (ll i = m; i >= n; i--)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repr(i, n) for (ll i = (n)-1; i >= 0; --i)
#define mod 1000000007
#define MOD 998244353
constexpr ll INF = 4e18;
 
using vi = vector<int>;
using vll = vector<ll>;
 
///////////////////////////////////////////////////////////////////////////////////////////
 
 
void solve() {
    ll n;
    cin >> n;
 
    vll dp(n+1, INT_MAX - 10);
 
    //statement: dp[i] = the min stepst to convert i-->0;
    //expression: dp[i] = min({dp[i-d1], dp[i-d2], dp[i-d3],_ _ _ _, }) + 1;
 
    dp[0] = 0;
    f(i, 1, 9)  dp[i] = 1;
 
    f(i, 10, n){
        ll temp = i;
        while(temp){
            ll d = temp%10;
            temp/=10;
            dp[i] = min(dp[i], dp[i-d] + 1);
        }
    }
 
    // f(i, 0, n){
    //     cout << dp[i] << " ";
    // }
 
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