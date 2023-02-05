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

/**
 * Description: Disjoint-set data structure.
 * Time: O(\alpha(N))$
 */
struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  UF uf1(n), uf2(n);
  rep(i, 0, m1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    uf1.join(a, b);
  }
  rep(i, 0, m2) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    uf2.join(a, b);
  }
  int ans = 0;
  vector<array<int, 2>> edges;
  rep(i, 0, n) {
    rep(j, i + 1, n) {
      if (uf1.find(i) != uf1.find(j) && uf2.find(i) != uf2.find(j)) {
        edges.push_back({i, j});
        uf1.join(i, j);
        uf2.join(i, j);
      }
    }
  }
  cout << edges.size() << endl;
  for (auto &e : edges) {
    cout << e[0] + 1 << " " << e[1] + 1 << endl;
  }
}

int main() {
  sync
      // #ifndef ONLINE_JUDGE
      //     freopen("input.txt", "r", stdin);
      //     freopen("output.txt", "w", stdout);
      // #endif

      ll T = 1;
  //   cin >> T;
  while (T--) {
    solve();
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}