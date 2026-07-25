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
 
const int MAXN = 1e5;
 
void solve() {
    ll n;
    cin >> n;
 
    vll x(n);
    rep(i, n)   cin >> x[i];
 
    vll dp(MAXN+7, 0);
    //dp state: dp[i] : i is the possible sum by caluculating
 
    dp[0] = 1;
    vll temp;
 
    for(auto e : x) {
        temp.clear();
 
        f(i, 0, MAXN){
            if(dp[i]){
                temp.push_back(e+i);
            }
        }
 
        for(auto it : temp) {
            dp[it] = 1;
        }
 
    }
 
    vll ans;
 
    f(i, 1, MAXN){
        if(dp[i]){
            ans.push_back(i);
        }
    }
 
    sort(ans.begin(), ans.end());
 
    cout << ans.size() << endl;
    for(auto it : ans){
        cout << it << " ";
    }
 
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