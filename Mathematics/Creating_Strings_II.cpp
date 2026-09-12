#include <bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> multisett;
 
// AUTHOR : MANMATH HATTE
// OM NAMAH SHIVAAY
// JAI SHRI RAM
 
#define ld long double
#define ll long long
#define f(i, m, n) for (int i = m; i <= n; i++)
#define rf(i, m, n) for (int i = m; i >= n; i--)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n)-1; i >= 0; --i)
#define mod 1000000007
#define imx INT_MAX
#define imn INT_MIN
#define lmx LONG_MAX
#define lmn LONG_MIN
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
 
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x)
#endif
 
ll add(ll a, ll b, ll m = mod) { a %= m; b %= m; return (a + b) % m; }
ll sub(ll a, ll b, ll m = mod) { a %= m; b %= m; return (a - b + m) % m; }
ll mul(ll a, ll b, ll m = mod) { a %= m; b %= m; return (1ll * a * b) % m; }
ll pow(ll a, ll b, ll m = mod) { a %= m; ll res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
 
 
//////////////////////////////solution fn starts here/////////////////////////////
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<ll> facto(1000001);
    facto[0] = 1;
    f(i, 1, 1000000){
        facto[i] = (i*facto[i-1])%mod;
    }
    
    string s;
    cin >> s;
    
    int n = s.size();
    
    map<char, int> mp;
    for(char c : s) {
        mp[c]++;
    }
    
    ll ans = facto[n] % mod;
    
    for(auto it : mp) {
        ans = ( ans * pow(facto[it.second]%mod, mod-2, mod) ) % mod;
    }
    
    cout << ans << endl;
 
    return 0;
}
//sample outputs
/*
 
*/