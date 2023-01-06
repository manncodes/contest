/*
    Author: manncodes
    Time : 05 January 2023  21:06:23
    File: c.cpp
    ee5a1508-3b18-4856-9040-9d0230855d6f
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
using ll = long long;
using ld = long double;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rng(0);


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> x(n + 1, -1), y(n + 1, -1);
    vector<int> perm1(n, 0), perm2(n, 0);
    set<int> s1, s2;
    int p = 0;
    bool NO_COND = 1;
    rep(i, 0, n) {
        cin >> a[i];
    }

    rep(i, 0, n) {
        if (x[a[i]] == -1) {
            x[a[i]] = i;
            perm1[i] = a[i];
        }
        else if (y[a[i]] == -1) {
            y[a[i]] = i;
            perm2[i] = a[i];
        }
        else {
            p = 1;
        }
    }

    if (p == NO_COND) {
        cout << "NO" << endl;
        return;
    }

    rep(i, 0, n) {
        if (x[i + 1] == -1) s1.insert(i + 1);
        if (y[i + 1] == -1) s2.insert(i + 1);
    }
    
    for (int i = 0; i < n; i++) {
        int perm = (perm1[i] == 0) ? perm2[i] : perm1[i];
        auto& s = (perm1[i] == 0) ? s1 : s2;
        auto it = s.upper_bound(perm);
        if (it == s.begin()) {
            p = NO_COND;
            break;
        }
        it--;
        if (perm1[i] == 0) perm1[i] = *it;
        else perm2[i] = *it;
        s.erase(it);
    }
    if (p == NO_COND) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    rep(i, 0, n) cout << perm1[i] << " ";
    cout << endl;
    rep(i, 0, n) cout << perm2[i] << " ";
    cout << endl;
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