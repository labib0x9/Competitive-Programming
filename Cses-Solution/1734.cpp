// https://cses.fi/problemset/task/1734
#include <bits/stdc++.h>
using namespace std;
 
#define intll long long
#define endl '\n'
 
template<typename T>
void PRINT(vector<T>& arr) {
    for (int i = 0; i < int(arr.size()); i++)
        cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}
 
template<typename T = int>
struct binary_index_tree {
#define LSONE(x) ((x) & -(x))
 
    int N;
    vector<T> t;
 
    binary_index_tree() {}
    binary_index_tree(int n) : N(n) {
        t.resize(N + 1);
    }
    binary_index_tree(vector<int>& arr) {
        N = int(arr.size());
        t.resize(N + 1);
 
        for (int i = 1; i <= N; i++)
            update(i, arr[i - 1]);
    }
 
    void update(int i, T x) {
        while (i <= N) {
            t[i] += x;
            i += LSONE(i);
        }
    }
 
    T query(int i) {
        T summ = 0;
        while (i > 0) {
            summ += t[i];
            i -= LSONE(i);
        }
        return summ;
    }
};
 
void solution() {
 
    int n, k;
    cin >> n >> k;
 
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
 
    vector<vector<array<int, 2>>> queries(n + 1);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        queries[l].push_back({r, i});
    }
 
    vector<int> ans(k);
    binary_index_tree<int> bt(n + 1);
    map<int, int> mp;
    for (int i = n; i > 0; i--) {
        if (mp.find(arr[i - 1]) == mp.end()) {
            mp[arr[i - 1]] = i;
            bt.update(i, 1);
        } else {
            bt.update(mp[arr[i - 1]], -1);
            mp[arr[i - 1]] = i;
            bt.update(i, 1);
        }
        for (auto [r, idx] : queries[i]) {
            ans[idx] = bt.query(r);
        }
    }
 
    for (int i = 0; i < k; i++) {
        cout << ans[i] << endl;
    }
}
 
int32_t main() {
 
    // Test Case
    bool TEST_CASE = !true;
 
    ios::sync_with_stdio(false) ; cin.tie(0) ;
 
    int t_c = 1, tt_c = 1;
    if (TEST_CASE) cin >> t_c;
 
    while (t_c--) {
        // cout << "Case " << tt_c++ << ": ";
        solution();
        // if (t_c) cout << '\n';
    }
 
    return 0;
}