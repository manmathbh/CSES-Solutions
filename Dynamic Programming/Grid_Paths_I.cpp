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
    ll n;
    cin >> n;
 
    // vector<vector<char>> grid(n, vector<char> (n));
    // rep(i, n){
    //     rep(j, n)   cin >> grid[i][j];
    // }
 
    vector<string> grid(n);
    rep(i, n)   cin >> grid[i];
 
    vector<vll> dp(n, vll(n, 0));
 
    //statement: dp[i][j] = the no. of paths from [0][0] to [i][j]
    //expr: dp[i][j] = dp[i-1][j] + dp[i][j-1]
 
    rep(i, n){
        if(grid[0][i] == '*')   break;   
        dp[0][i] = 1;
    }
 
    rep(i, n){
        if(grid[i][0] == '*')   break;
        dp[i][0] = 1;
    }
 
    // f(i, 0, n-1){
    //     f(j, 0, n-1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
 
    f(i, 1, n-1){
        f(j, 1, n-1){
            if(grid[i][j] == '*')   continue;
 
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
        }
    }
 
    cout << dp[n-1][n-1];
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