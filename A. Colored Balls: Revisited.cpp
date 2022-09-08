#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define forn(i,n) for(int i = 0; i < n; ++i)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define ln "\n"
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long

/*--------------------------------------------------------------------------------------------------------------------*/
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (a == 0) return b; else return gcd (b % a, a);}
/*--------------------------------------------------------------------------------------------------------------------*/

// (づ｡◕‿‿◕｡)づ you got this

//  need to get smarter at all costs

int remaining(vector<int> &v1, int ind){
    multiset<int> s1;
    for(int i = 0; i < (int)v1.size(); i++){
        if(i != ind) s1.insert(v1[i]);
    }
    while(!s1.empty() && (int)s1.size() > 1){
        auto it1 = s1.begin();
        auto it2 = s1.end();
        it2--;
        int val1 = *(it1);
        int val2 = *(it2);
        s1.erase(it1);
        s1.erase(it2);
        s1.insert(val1 - 1);
        s1.insert(val2 - 1);
        forn(i,2){
            if(!s1.empty() && *(s1.begin()) == 0){
                s1.erase(s1.begin());
            }
        }

    }
    if(s1.empty()){
        return 0;
    }
    else{
        return *(s1.begin());
    }
}

void solve() {
    int n; cin >> n;
    vector<int> v1(n);
    forn(i,n) cin >> v1[i];
    sort(all(v1));
    int count = 0;
    forn(i,n){
        int rem = remaining(v1,i);
        if(rem < v1[i]){
            count ++;
        }
    }
    cout << count << ln;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    int it; cin >> it;
    forn(_it,it) solve();
}

