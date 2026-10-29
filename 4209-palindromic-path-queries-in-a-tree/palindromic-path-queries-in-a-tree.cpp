
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit;
    vector<int> mask;
    int timer = 0;
    int rootMask;

    void dfs(int root) {
        vector<int> parent(n, -1);
        vector<int> st;
        st.push_back(root);
        parent[root] = root;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = ++timer;
            up[u][0] = parent[u];

            for (int j = 1; j < LOG; j++) {
                up[u][j] = up[up[u][j - 1]][j - 1];
            }

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        for (int u = 0; u < n; u++) {
            tout[u] = tin[u];

            for (int v : adj[u]) {
                if (parent[v] == u) {
                    tout[u] = max(tout[u], tout[v]);
                }
            }
        }

        // Compute subtree intervals using reverse traversal order.
        vector<int> order(n);
        for (int u = 0; u < n; u++) {
            order[tin[u] - 1] = u;
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (u != root) {
                tout[parent[u]] = max(tout[parent[u]], tout[u]);
            }
        }
    }

    void updateBIT(int i, int val) {
        for (; i <= n; i += i & -i) {
            bit[i] ^= val;
        }
    }

    int queryBIT(int i) {
        int res = 0;

        for (; i > 0; i -= i & -i) {
            res ^= bit[i];
        }

        return res;
    }

    void rangeUpdate(int l, int r, int val) {
        updateBIT(l, val);

        if (r + 1 <= n) {
            updateBIT(r + 1, val);
        }
    }

    int getPrefixMask(int u) {
        return rootMask ^ queryBIT(tin[u]);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;

        LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG, 0));
        bit.assign(n + 1, 0);
        mask.assign(n, 0);

        for (int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');
        }

        rootMask = mask[0];

        dfs(0);

        // Initialize root-to-node prefix masks.
        for (int u = 0; u < n; u++) {
            rangeUpdate(tin[u], tout[u], mask[u]);
        }

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            char c;

            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int newMask = 1 << (c - 'a');
                int change = mask[u] ^ newMask;

                rangeUpdate(tin[u], tout[u], change);
                mask[u] = newMask;
            } else {
                ss >> v;

                int w = lca(u, v);

                int pathMask = getPrefixMask(u)
                             ^ getPrefixMask(v)
                             ^ mask[w];

                ans.push_back(
                    pathMask == 0 ||
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
