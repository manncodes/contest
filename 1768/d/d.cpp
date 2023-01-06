/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int a[MAX];
int p[MAX];

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	p[u] = v;
}

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) p[i] = i;
	for (i = 1; i <= N; i++) cin >> a[i], uni(a[i], i);
	int cnt = 0;
	for (i = 1; i <= N; i++) if (p[i] == i) cnt++;
	int c = 0;
	for (i = 1; i < N; i++) if (find(i) == find(i + 1)) c = 1;
	if (cnt == N) {
		cout << 1 << ln;
		return;
	}
	if (c) cout << N - cnt - c << ln;
	else cout << N - cnt + 1 << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}