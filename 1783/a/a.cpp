/*
    Author: manncodes
    Time : 08 January 2023  20:05:53
    File: a.cpp
    22515f52-774a-4101-a2e6-a12d8a47beb2
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

bool helper(vector<int>& a) {
    int sum = 0;
    for (auto i : a) {
        if (i == sum) {
            return false;
        }
        sum += i;
    }
    return true;
}

// Function to solve the problem
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    reverse(all(a));
    vector<int> ans;
    for (int i = 0; i < n / 2; ++i) {
        ans.push_back(a[i]);
        ans.push_back(a[n - i - 1]);
    }
    if (n % 2) ans.push_back(a[n / 2]);
    if (helper(ans)) {
        cout << "YES" << endl;
        for (auto i : ans) cout << i << " ";
    }
    else {
        cout << "NO" << endl;
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