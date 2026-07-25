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
 
//////////////////////////////////////////////////////////////////////////////////////
 
void solve() {
    int a, b;
    cin >> a >> b;
 
    vector<vi> dp(a+1, vi (b+1));
 
    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            if(i == j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = INT_MAX;
                for(int k = 1; k < i; k++){
                    dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
                }
 
                for(int k = 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
                }
            }
        }
    }
 
    cout << dp[a][b];
 
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