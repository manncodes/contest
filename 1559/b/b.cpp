#include <bits/stdc++.h>
using namespace std;

#define sync                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
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

char other(char c) { return c == 'R' ? 'B' : 'R'; }

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int p = 0;
  while (p < n && s[p] == '?')
    p++;
  char a = (p < n ? s[p] : 'R');
  auto t = s;
  rep(i, 0, p) t[i] = (i % 2 == p % 2 ? a : other(a));
  rep(i, p, n) {
    t[i] = (s[i] != '?' ? s[i] : other(a));
    a = t[i];
  }
  cout << t << "\n";
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
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}