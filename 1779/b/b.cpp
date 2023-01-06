/*
    Author: manncodes
    Time : 03 January 2023  20:16:01
    File: b.cpp
    35fc4559-60c3-4aa7-850b-92b04c02c7e2
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
    int x = n / 2;

    if (n == 3) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            cout << 1 << " " << -1 << " ";
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < n / 2; i++) {
            cout << 1 - x << " " << x << " ";
        }
        cout << 1 - x << endl;
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