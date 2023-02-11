#include <bits/stdc++.h>
using namespace std;

#define sync                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
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
#define unq(a)                                                                 \
  sort(all(a));                                                                \
  a.resize(unique(all(a)) - a.begin())
#define ar array
#define vt vector
#define endl '\n'
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  int l, n, m;
  cin >> l;
  vector<int> x(l);
  rep(i, 0, l) cin >> x[i];
  cin >> n;
  vector<int> b(n);
  rep(i, 0, n) { cin >> b[i]; }
  cin >> m;
  vector<int> g(m);
  rep(i, 0, m) { cin >> g[i]; }

  sort(all(x));
  sort(all(b));
  sort(all(g));
  int ans = 0;

  for (int i = 0, j = 0, k = 0; k < l and j < m and i < n;) {
    if (abs(b[i] - g[j]) <= 1 and abs(x[k] - g[j]) <= 1 and
        abs(x[k] - b[i]) <= 1) {
      ans++;
      i++, j++, k++;
    } else {
      vector<int> idx = {b[i], g[j], x[k]};
      auto min_idx = distance(idx.begin(), min_element(all(idx)));
      if (min_idx == 0) {
        i++;
      } else if (min_idx == 1) {
        j++;
      } else {
        k++;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  sync
#ifndef ONLINE_JUDGE
      freopen("test1.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ll T = 1;
  //   cin >> T;
  while (T--) {
    solve();
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}