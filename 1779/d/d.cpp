/*
    Author: manncodes
    Time : 05 January 2023  18:50:23
    File: d2.cpp
    7fc9910b-5081-47d7-9050-015a06952ff7
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

//----------------- DEBUG -----------------//
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
// for multiset
ostream& operator<<(ostream& os, const multiset<int>& v)
{
    os << '{';
    string sep;
    for (const auto& x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

#define dbg(...) cerr << "" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)



// -----------------  CODE STARTS FROM HERE ----------------- //
void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    cin >> m;
    vector<int> c(m);
    rep(i, 0, m) cin >> c[i];
    multiset<int> s(all(c));

    dbg(a);
    dbg(b);
    rep(i, 0, n) {
        if(a[i] == b[i]) continue;

        if (a[i] < b[i]) {
            cout << "NO" << endl;
            dbg("NO from 1");
            return;
        }
        if (s.find(b[i]) == s.end()) {
            cout << "NO" << endl;
            dbg("NO from 2");
            dbg(i, b[i], s);
            return;
        }
    }
    

    multiset<int> active;
    vector<bool> check(n, false);
    rep(i, 0, n) {
        if (a[i] == b[i]) {
            check[i] = true;
            continue;
        }
        else {
            //check if b[i] is present in s[i]
            if (s.find(b[i]) == s.end()) {
                // check also if b[i] is present in active
                if (active.find(b[i]) == active.end()) {
                    {
                        cout << "NO" << endl;
                        dbg("NO from 3");
                        dbg(i, b[i], active);
                        return;
                    }
                }else{
                    // present in active
                    check[i] = true;
                }

            }
            else {
                // if the s[i] is available use it
                active.insert(b[i]);
                check[i] = true;

                // check in active
                dbg(i, b[i], active);  
                bool found = false;
                for (auto it = active.begin(); it != active.end(); it++) {
                    if (*it == b[i]) {
                        found = true;
                        check[i] = true;
                        break;
                    }
                    if (*it < b[i]) {
                        active.erase(it);
                    }
                }
                s.erase(s.find(b[i]));
            }
        }
    }

    rep(i, 0, n) {
        if (!check[i]) {
            cout << "NO" << endl;
            dbg("NO from 4");
            return;
        }
    }
    cout << "YES" << endl;
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