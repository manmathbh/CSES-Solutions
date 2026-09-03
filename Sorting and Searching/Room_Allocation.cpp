#include <bits/stdc++.h>
using namespace std;
 
#define ld long double
#define ll long long
#define f(i, m, n) for (int i = m; i <= n; i++)
#define rf(i, m, n) for (int i = m; i >= n; i--)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
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
#define F first
#define S second
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
 
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
// Constants
constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 998244353;
 
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
 
//DSU_Manmath
class DisjointSets {
  private:
	vector<int> par;
	vector<int> sz;
  public:
	DisjointSets(int n){
	    par.resize(n+1);
	    sz.resize(n+1, 1);
		f(i, 0, n) { par[i] = i; }
	}
 
	/** @return the "representative" node in x's component */
	int find(int u) { return par[u] == u ? u : (par[u] = find(par[u])); }
 
	/** @return whether the merge changed connectivity */
	void unite(int u, int v) {
		int u_root = find(u);
		int v_root = find(v);
		if (u_root == v_root) { return; }
 
		if (sz[u_root] < sz[v_root]) { swap(u_root, v_root); }
		par[v_root] = u_root;
		sz[u_root] += sz[v_root];
	}
 
	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};
////////////////////////////////////////////////////////////////////////////////
 
void solve() {
    int n;
    cin >> n;
    
    multimap<pii, int> mp;
    
    f(i, 0, n-1) {
        int x, y;
        cin >> x >> y;
        
        mp.insert({{x,y}, i});
    }
    
    int cnt = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi room_allocated(n);
    
    // for(auto x: mp){
    //     cout << x.F.F << " " << x.F.S <<" " << x.S << endl;
    // }
    for(auto it : mp) {
        int a = it.F.F;
        int b = it.F.S;
        int c;
        if(pq.empty() || pq.top().F >= a){
            c = ++cnt;
        }
        else{
            c = pq.top().S;
            pq.pop();
        }
        
        pq.push({b, c});
        room_allocated[it.S] = c;
    }
    
    cout << cnt << endl;
    for(auto x : room_allocated){
        cout << x << " ";
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      freopen("Error.txt", "w", stderr);
    #endif
    //precomputeFactorials();
    ll t = 1;
    //cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}