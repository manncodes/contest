#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define ar array
#define vt vector
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<bool> used(2 * n, false);
    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) {
      cin >> a[i] >> b[i];
      --a[i]; --b[i];
      used[a[i]] = true;
      used[b[i]] = true;
    }
    vector<int> r;
    for (int i = 0; i < 2 * n; i++) {
      if (!used[i]) {
        r.push_back(i);
      }
    }
    int cnt = (int) r.size();
    for (int i = 0; i < cnt / 2; i++) {
      a.push_back(r[i]);
      b.push_back(r[i + cnt / 2]);
    }
    assert((int) a.size() == n);
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        swap(a[i], b[i]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i] < a[j] && a[j] < b[i] && b[i] < b[j]) {
          ans += 1;
        }
      }
    }
    cout << ans << '\n';
}

int main(){
    sync
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ll T=1;
    cin >> T;
    while (T--){
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}