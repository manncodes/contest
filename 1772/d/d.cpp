/*
    Author: manncodes
    Time : 23 December 2022  14:59:14
    File: d.cpp
    b7e07aea-ed48-43de-8e16-f10537dfabaa
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
    // You are given an array a consisting of n integers. The array is sorted if a1≤a2≤⋯≤an.
    // You want to make the array a sorted by applying the following operation exactly once:
    // choose an integer x, then for every i∈[1,n], replace ai by |ai−x|.
    // Find any value of x that will make the array sorted, or report that there is no such value.

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &i : a) cin >> i;
    auto max = *max_element(all(a));

    bool has_peak = false;
    rep(i,1,n-1){
        if(a[i] > a[i+1] && a[i] > a[i-1]){
            has_peak = true;
            break;
        }
    }
    
    bool sorted = true;
    rep(i,1,n){
        if(a[i] < a[i-1]){
            sorted = false;
            break;
        }
    }

    if(has_peak){
        cout << -1 << endl;
        return;
    }else{
        // valley -> max elem, sorted -> 0
        if(sorted) cout << 0 << endl;
        else cout << max << endl;
    }
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