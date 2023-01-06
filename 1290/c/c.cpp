
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class dsu {
 public:
  vector<int> p;
  vector<int> eq;
  vector<int> neq;
  vector<int> pc;
  vector<int> must;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    eq.assign(n, 1);
    neq.assign(n, 0);
    pc.assign(n, 0);
    must.assign(n, -1);
  }

  inline int get(int x) {
    if (x == p[x]) {
      return x;
    }
    int npx = get(p[x]);
    pc[x] ^= pc[p[x]];
    p[x] = npx;
    return p[x];
  }

  inline bool unite(int x, int y, int z) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      pc[x] = z;
      if (z == 0) {
        eq[y] += eq[x];
        neq[y] += neq[x];
      } else {
        eq[y] += neq[x];
        neq[y] += eq[x];
      }
      if (must[x] != -1) {
        int val = must[x] ^ pc[x];
        assert(must[y] == -1 || must[y] == val);
        must[y] = val;
      }
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<int>> at(n);
  for (int i = 0; i < k; i++) {
    int foo;
    cin >> foo;
    for (int j = 0; j < foo; j++) {
      int x;
      cin >> x;
      --x;
      at[x].push_back(i);
    }
  }
  dsu d(k);
  auto Eval = [&](int r) {
    if (d.must[r] == 0) {
      return d.neq[r];
    }
    if (d.must[r] == 1) {
      return d.eq[r];
    }
    return min(d.neq[r], d.eq[r]);
  };
  const int inf = (int) 1e9;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (at[i].size() == 0) {
      assert(s[i] == '1');
    } else {
      if (at[i].size() == 1) {
        int v = at[i][0];
        int r = d.get(v);
        ans -= Eval(r);
        int val;
        if ((s[i] == '1' && d.pc[v] == 0) || (s[i] == '0' && d.pc[v] == 1)) {
          val = 0;
        } else {
          val = 1;
        }
        assert(d.must[r] == -1 || d.must[r] == val);
        d.must[r] = val;
        ans += Eval(r);
      } else {
        int v = at[i][0];
        int u = at[i][1];
        int rv = d.get(v);
        int ru = d.get(u);
        if (rv != ru) {
          ans -= Eval(ru);
          ans -= Eval(rv);
          d.unite(rv, ru, (s[i] == '0') ^ d.pc[v] ^ d.pc[u]);
          ans += Eval(ru);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
