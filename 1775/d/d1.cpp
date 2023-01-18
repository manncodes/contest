#include "bits/stdc++.h"

using namespace std;

#define ll long long
const int MAXN = 400000;

int n;
int a[MAXN];

int prime[MAXN];
int pf[MAXN];

int dist[MAXN * 2];
int pv[MAXN * 2];
vector<int> g[MAXN * 2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(prime, prime + MAXN, 1);
    for (int i = 2; i < MAXN; i++) {
        if (!prime[i]) continue;
        for (int j = i; j < MAXN; j += i) {
            prime[j] = (i == j);
            pf[j] = i;
        }
    }

    fill(dist, dist + MAXN * 2, 1e9);
    fill(pv, pv + MAXN * 2, -1);

    cin >> n;
    for (int i = 1; i <= n; i++) {

        cin >> a[i];

        while (a[i] > 1) {
            int p = pf[a[i]];
            while (a[i] % p == 0) a[i] /= p;
            // cout << i << ": have " << p << endl;
            g[i].push_back(MAXN + p);
            g[MAXN + p].push_back(i);
        }

    }

    int s, t; cin >> s >> t;

    dist[s] = 0;
    queue<int> curr;
    curr.push(s);

    while (curr.size()) {
        int x = curr.front();
        curr.pop();
        // cout << "at " << x << " with " << dist[x] << endl;
        for (int i : g[x]) {
            // cout << x << " -> " << i << endl;
            if (dist[i] > dist[x] + 1) {
                dist[i] = dist[x] + 1;
                pv[i] = x;
                curr.push(i);
            }
        }
    }

    if (dist[t] > 1e8) {
        cout << "-1\n";
        return 0;
    }

    vector<int> ans;
    while (t != -1) {
        if (t <= n) ans.push_back(t);
        t = pv[t];
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
    cout << "\n";

}
