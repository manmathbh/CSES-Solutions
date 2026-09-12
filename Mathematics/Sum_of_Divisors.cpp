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
 
 
//////////////////////////////solution fn starts here/////////////////////////////
 
 
 
long long int inverse(long long int i){
    if(i==1) return 1;
    return (mod - ((mod/i)*inverse(mod%i))%mod+mod)%mod;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i*i<=n;i++)
    {
        ans+=((n/i)*i)%mod;
        ans%=mod;
    }
    ll l=(ll)sqrt(n);
    for(ll i=sqrt(n);i>=1;i--)
    {
        ll r=n/i;
        ll sum=0;
        sum+=((((r%mod)*((r+1)%mod))%mod)*inverse(2))%mod;
        sum%=mod;
        sum-=((((l%mod)*((l+1)%mod))%mod)*inverse(2))%mod;
        sum=(sum+mod)%mod;
        sum=(sum*i)%mod;
        l=r;
        ans=(ans+sum)%mod;
        //cout<<sum<<" ";
    }
    cout<<ans;
}