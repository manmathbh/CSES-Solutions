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
    int n, x;
    cin >> n >> x;
 
    vi price(n), pages(n);
    for (int&v : price) cin >> v;
    for (int&v : pages) cin >> v;
 
    //ll dp[n+1][x+1];
    vector<vi> dp(n+1, vi(x+1, 0));
 
    //statement: dp[i][j] = the max no of pages can buy from i = 0 to i in price j
    //expression: dp[i][j] = max(dp[i-1][j - cost[i]] + pages[i], dp[i-1][j] + 0);
 
    f(i, 1, n){
        f(j, 0, x){
         
            dp[i][j] = dp[i-1][j];
            int left = j-price[i-1];
            if (left >= 0) {
	            dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
            }
            
        }
    }
 
    // f(i, 0, n){
    //     f(j, 0, x){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
 
    cout << dp[n][x];
    
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