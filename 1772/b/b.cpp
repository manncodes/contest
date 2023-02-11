/*
    Author: manncodes
    Time : 23 December 2022  13:49:35
    File: b.cpp
    6c185a23-4b70-496b-807e-a1fb0d97e495
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
 
using pii = pair<int , int>;
using ll = long long;
using ld = long double;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rng(0);

void solve(){
    vector<vector<int>> a(2, vector<int>(2));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cin >> a[i][j];
        }
    }

    // check if always a[0][0] < a[1][0] and a[0][1] < a[1][1] then yes
    // if not rotate the matrix by 90 degree and check again for full turn if not then no

    rep(i,0,4){
        if(a[0][0] < a[1][0] and a[0][0] < a[0][1] and a[0][1] < a[1][1] and a[1][0] < a[1][1]){
            cout << "YES" << endl;
            return;
        }
        swap(a[0][0], a[0][1]);
        swap(a[0][1], a[1][1]);
        swap(a[1][1], a[1][0]);
    }

    cout << "NO" << endl;
}

int main(){
//    #ifndef ONLINE_JUDGE 
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
//    #endif
 
    sync

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "processor time: " << clock() / (double) CLOCKS_PER_SEC << "s    ";
    return 0;
}