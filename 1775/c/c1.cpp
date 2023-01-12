/*
    Author: manncodes
    Time : 11 January 2023  19:33:15
    File: c1.cpp
    256bed8c-fb75-41ba-a5bf-3dd7e1a0bfbf
"*/
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;

using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k) -> iterator of kth element (in sorted fashion : low - high)
// order_of_key(x) -> #numbers strictly less than x

#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("avx2")

#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) x.begin(),x.end()
#define unq(a) sort(all(a));a.resize(unique(all(a)) - a.begin())
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--) 
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()

#define endl '\n'

using pii = pair<int, int>;
using ll = long long; // range[-9e18, 9e18]
using ld = long double; // range[1e-18, 1e18]

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rng(0);

ll query(ll a, ll b) {
    ll res = 0;
    for (int i = 61; i >= 0; i--) {
        if ((a >> i & 1) && (a >> i) == (b >> i)) {
            res = res | 1LL << i;
        }
    }
    return res;
}

// solution using binary search
void solve() {
    ll n, x;
    cin >> n >> x;
    ll l = n, r = 5e18;
    ll mid, res = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (query(n, mid) <= x) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    if (res != -1 && query(n, res) == x) {
        cout << res << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    //    #ifndef ONLINE_JUDGE 
    //       freopen("input.txt", "r", stdin);
    //       freopen("output.txt", "w", stdout);
    //    #endif

    sync

        int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    cerr << "processor time: " << clock() / (double)CLOCKS_PER_SEC << "s    ";
    return 0;
}