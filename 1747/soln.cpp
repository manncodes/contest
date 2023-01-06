/*
    Author: manncodes
    Time : 05 November 2022  10:04:04
    File: soln.cpp
    d3f78251-582f-4a52-bbe9-c7453eae568f
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

#define fi first
#define se second
#define endl '\n'
 
using pii = pair<int , int>;
using ll = long long;
using ld = long double;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rng(0);

// There is a task recorded in the two-dimensional array tasks in the format [start, end, period], indicating that the task needs to be completed within the time range start to end, and period indicates the length of time required to complete the task. Note:
// 1. The period can be discontinuous time. 2. The start and end are included.
// 3. The computer can handle an unlimited number of tasks at the same time. Please calculate the minimum time that the computer can process all the tasks.

// tasks = [[1,3,2], [2,5,3], [5,6,2]] -> 4

void solve(){
    int n; cin >> n;
    vector<vector<int>> tasks(n, vector<int>(3));
    for(auto &v : tasks) for(auto &x : v) cin >> x;
    sort(all(tasks), [&](auto &a, auto &b){
        return a[1] < b[1];
    });
    // find all overlapping tasks
    vector<tuple<int, int, int>> overlaps; // taskA, taskB, overlap time
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(tasks[i][1] < tasks[j][0]) break;
            int overlap = min(tasks[i][1], tasks[j][1]) - max(tasks[i][0], tasks[j][0]) + 1;
            if(overlap > 0) overlaps.emplace_back(i, j, overlap);
        }
    }
    

}

int main(){
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    sync

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    cerr << "processor time: " << clock() / (double) CLOCKS_PER_SEC << "s    ";
    return 0;
}