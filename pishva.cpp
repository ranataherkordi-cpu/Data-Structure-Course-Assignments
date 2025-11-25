#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1933];
int a[1933];

long long min_power_needed(int start, int n) {
    vector<bool> conquered(n, false);
    long long current_power = a[start];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    conquered[start] = true;
    for (int v : adj[start]) {
        if (!conquered[v]) {
            pq.push({a[v], v});
        }
    }

    long long additional_power = 0;
    while (!pq.empty()) {
        auto [needed_power, u] = pq.top();
        pq.pop();

        if (conquered[u]) continue;

        if (current_power > needed_power) {
            current_power += a[u];
        } else {
            additional_power += (needed_power + 1 - current_power);
            current_power = needed_power + 1 + a[u];
        }

        conquered[u] = true;
        for (int v : adj[u]) {
            if (!conquered[v]) {
                pq.push({a[v], v});
            }
        }
    }

    return additional_power;
}

int main() {


    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int v = 0; v < n; v++) {
        cout << min_power_needed(v, n);
        if (v != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
