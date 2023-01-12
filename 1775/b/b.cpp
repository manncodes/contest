/*
    Author: manncodes
    Time : 11 January 2023  12:18:47
    File: b.cpp
    81ef5edc-bd84-442b-b2e2-9a7a98c1fb7c
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

#define F_OR(i, a, b, s) \
    for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...)       \
    F_ORC(__VA_ARGS__) \
    (__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << '{';
    string sep;
    for (const auto& x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
template <typename T, size_t size>
ostream& operator<<(ostream& os, const array<T, size>& arr)
{
    os << '{';
    string sep;
    for (const auto& x : arr)
        os << sep << x, sep = ", ";
    return os << '}';
}
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

#define dbg(...) cerr << "" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)



ll OR(vector<ll> a) {
    ll ans = 0;
    for (auto x : a) {
        ans |= x;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    map<int, int > mp;
    vector<vector<int>> v(n);
    rep(i, 0, n) {
        int x;
        cin >> x;
        v[i].resize(x);
        rep(j, 0, x) {
            int y;
            cin >> y;
            v[i][j] = y;
            mp[y]++;
        }
    }

    rep(i, 0, n) {
        bool ok = true;
        for (auto x : v[i]) {
            if (mp[x] == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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