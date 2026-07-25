#include <bits/stdc++.h>
using namespace std;
 
#define ld long double
#define ll long long
#define f(i, m, n) for (int i = m; i <= n; i++)
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
    string s, t;
    cin >> s;   //n
    cin >> t;   //m
    
    ll n = s.size();
    ll m = t.size();
 
    vector<vi> dp(n+1, vi(m+1, 0));
 
    //dp state: dp[i][j] = the min no of operations required to string s (fron s0 to si to fron t0 to tj)
    // dp expressions: dp[i][j] = min(dp[i-1]dp[j-1], dp[i-1][j], dp[i][j-1]) + 1;
 
    f(i, 0, n){
        dp[i][0] = i;
    }
 
    f(i, 0, m){
        dp[0][i] = i;
    }
 
    f(i, 1, n){
        f(j, 1, m){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
            }
        }
    }
 
    // f(i, 0, n){
    //     f(j, 0, m){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
 
    cout << dp[n][m];
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // ll t;
    // cin >> t;
 
    // while (t--) {
    //     solve();
    // }
 
    solve();
 
    return 0;
}