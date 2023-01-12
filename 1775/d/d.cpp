/*
    Author: manncodes
    Time : 11 January 2023  22:16:38
    File: d.cpp
    2f0cc5dc-ba66-475a-b9de-babe6a143561
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

#define N 300005

int n, a[N];
int cnt = 0;
vector <int> g[2 * N];
bool mp[N];
int id[N];
queue <int> q;
int dis[2 * N], lst[2 * N];

void solve() {
    cin >> n, cnt = n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int now = a[i];
        for (int j = 2; j * j <= now; ++j) {
            if (now % j == 0) {
                while (now % j == 0) now /= j;
                if (mp[j]) {
                    g[id[j]].push_back(i);
                    g[i].push_back(id[j]);
                }
                else {
                    mp[j] = true;
                    id[j] = ++cnt;
                    g[id[j]].push_back(i);
                    g[i].push_back(id[j]);
                }
            }
        }
        if (now > 1) {
            if (mp[now]) {
                g[id[now]].push_back(i);
                g[i].push_back(id[now]);
            }
            else {
                mp[now] = true;
                id[now] = ++cnt;
                g[id[now]].push_back(i);
                g[i].push_back(id[now]);
            }
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        dis[i] = 1e9;
    }
    int st, en;
    cin >> st >> en;
    dis[st] = 0;
    q.push(st);
    while (q.size()) {
        int x = q.front(); q.pop();
        for (auto i : g[x]) {
            if (dis[i] > dis[x] + 1) {
                dis[i] = dis[x] + 1;
                lst[i] = x;
                q.push(i);
            }
        }
    }
    if (dis[en] == 1e9) cout << -1 << endl;
    else {
        cout << dis[en] / 2 + 1 << endl;
        stack <int> sta;
        for (int i = en; i != st; i = lst[i]) {
            if (i <= n) sta.push(i);
        }
        sta.push(st);
        while (sta.size()) {
            cout << sta.top() << ' ';
            sta.pop();
        }
    }
}



int main() {
    //    #ifndef ONLINE_JUDGE 
    //       freopen("input.txt", "r", stdin);
    //       freopen("output.txt", "w", stdout);
    //    #endif

    sync

        int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    cerr << "processor time: " << clock() / (double)CLOCKS_PER_SEC << "s    ";
    return 0;
}