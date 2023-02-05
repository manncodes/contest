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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<int> ans(n);
  iota(all(ans), 0);
  int tmp = 0;
  while (tmp < n && a[tmp] == 0)
    tmp++;
  ans.insert(ans.begin() + tmp, n);
  for (auto x : ans)
    cout << x + 1 << " ";
}

int main() {
  sync
      // #ifndef ONLINE_JUDGE
      //     freopen("input.txt", "r", stdin);
      //     freopen("output.txt", "w", stdout);
      // #endif

      ll T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << endl;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}