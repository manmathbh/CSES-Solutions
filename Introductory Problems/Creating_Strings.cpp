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
#define fr(i, m, n) for (int i = m; i >= n; i--)
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
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
 
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
ll powM(ll a, ll b, ll m = mod) { a %= m; ll res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
ll inverseM(ll a) { return powM(a, mod - 2, mod); }
 
#define MAX 100000
#define precomputeFactorials() ({ fact[0] = 1; for (int i = 1; i <= MAX; i++) fact[i] = fact[i - 1] * i % mod; invFact[MAX] = powM(fact[MAX], mod - 2, mod); for (int i = MAX - 1; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % mod; })
#define nCr(n, r) (((r) > (n)) ? 0 : fact[(n)] * invFact[(r)] % mod * invFact[(n) - (r)] % mod)
long long fact[MAX + 1], invFact[MAX + 1];
 
struct ManDS {
    vector<vector<vector<ll>>> M, A;
    int N, NN;
 
    ManDS(int n, int m) {
        this->N = n + 1;
        this->NN = m + 1;
        M.assign(n + 1, vector<vector<ll>>(m + 1, vector<ll>(2, 0)));
        A.assign(n + 1, vector<vector<ll>>(m + 1, vector<ll>(2, 0)));
    }
 
    void upd2(vector<vector<vector<ll>>> &t, int x, int y, long long mul, long long add) {
        for (int i = x; i < N; i += i & -i) {
            for (int j = y; j < NN; j += j & -j) {
                t[i][j][0] += mul;
                t[i][j][1] += add;
            }
        }
    }
    void upd1(int x, int y1, int y2, long long mul, long long add) {
        upd2(M, x, y1, mul, -mul * (y1 - 1));
        upd2(M, x, y2, -mul, mul * y2);
        upd2(A, x, y1, add, -add * (y1 - 1));
        upd2(A, x, y2, -add, add * y2);
    }
    void upd(int x1, int y1, int x2, int y2, long long val) {
        upd1(x1, y1, y2, val, -val * (x1 - 1));
        upd1(x2, y1, y2, -val, val * x2);
    }
    long long query2(vector<vector<vector<ll>>> &t, int x, int y) {
        long long mul = 0, add = 0;
        for (int i = y; i > 0; i -= i & -i) {
            mul += t[x][i][0];
            add += t[x][i][1];
        }
        return mul * y + add;
    }
    long long query1(int x, int y) {
        long long mul = 0, add = 0;
        for (int i = x; i > 0; i -= i & -i) {
            mul += query2(M, i, y);
            add += query2(A, i, y);
        }
        return mul * x + add;
    }
    long long query(int x1, int y1, int x2, int y2) {
        return query1(x2, y2) - query1(x1 - 1, y2) - query1(x2, y1 - 1) + query1(x1 - 1, y1 - 1);
    }
};
 
 
//////////////////////////////solution fn starts here/////////////////////////////
 
void solve() {
    string s;
    cin >> s;
    
    vector<string> permus;
    
    sort(all(s));
    
    do{
        permus.pb(s);
    }
    while(next_permutation(all(s)));
    
    cout << permus.size() << endl;
    
    for(auto& s : permus)   cout << s << endl;
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //precomputeFactorials();
    
    solve();
    
    return 0;
}
//sample outputs
/*
 
*/