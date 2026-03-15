// https://dmoj.ca/problem/coci20c6p5
#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
    for (int i = 0; i < int(arr.size()); i++)
        cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

const int MAXV = (int)1e9 + 9;
struct wavelet_tree {
    int lo, hi;
    wavelet_tree *l, *r;
    int *b, bsz;
    long long *c, csz; // c holds the prefix sum of elements

    wavelet_tree() {
        lo = 1;
        hi = 0;
        bsz = 0;
        csz = 0, l = NULL;
        r = NULL;
    }

    wavelet_tree(vector<int>& arr) {
        lo = 1;
        hi = 0;
        bsz = 0;
        csz = 0, l = NULL;
        r = NULL;
        init(arr.data(), arr.data() + arr.size(), -MAXV, MAXV);
    }

    void init(int *from, int *to, int x, int y) {
        lo = x, hi = y;
        if (from >= to) return;
        int mid = (lo + hi) >> 1;
        auto f = [mid](int x) {
            return x <= mid;
        };
        b = (int*)malloc((to - from + 2) * sizeof(int));
        bsz = 0;
        b[bsz++] = 0;
        c = (long long*)malloc((long long)(to - from + 2) * sizeof(long long));
        csz = 0;
        c[csz++] = 0;
        for (auto it = from; it != to; it++) {
            b[bsz] = (b[bsz - 1] + f(*it));
            c[csz] = (c[csz - 1] + (long long)(*it));
            bsz++;
            csz++;
        }
        if (hi == lo) return;
        auto pivot = stable_partition(from, to, f);
        l = new wavelet_tree();
        l->init(from, pivot, lo, mid);
        r = new wavelet_tree();
        r->init(pivot, to, mid + 1, hi);
    }

    // kth smallest element in [l, r]
    // for array [1,2,1,3,5] 2nd smallest is 1 and 3rd smallest is 2
    int kth(int l, int r, int k) {
        if (l > r) return 0;
        if (lo == hi) return lo;
        int inLeft = b[r] - b[l - 1], lb = b[l - 1], rb = b[r];
        if (k <= inLeft) return this->l->kth(lb + 1, rb, k);
        return this->r->kth(l - lb, r - rb, k - inLeft);
    }

    // count of numbers in [l, r] Less than or equal to k
    int LTE(int l, int r, int k) {
        if (l > r || k < lo) return 0;
        if (hi <= k) return r - l + 1;
        int lb = b[l - 1], rb = b[r];
        return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l - lb, r - rb, k);
    }

    // count of numbers in [l, r] equal to k
    int count(int l, int r, int k) {
        if (l > r || k < lo || k > hi) return 0;
        if (lo == hi) return r - l + 1;
        int lb = b[l - 1], rb = b[r];
        int mid = (lo + hi) >> 1;
        if (k <= mid) return this->l->count(lb + 1, rb, k);
        return this->r->count(l - lb, r - rb, k);
    }

    // sum of numbers in [l ,r] less than or equal to k
    long long sum(int l, int r, int k) {
        if (l > r || k < lo) return 0ll;
        if (hi <= k) return c[r] - c[l - 1];
        int lb = b[l - 1], rb = b[r];
        long long sum_left = this->l->sum(lb + 1, rb, k);
        long long sum_right = this->r->sum(l - lb, r - rb, k);
        return sum_left + sum_right;
    }

    ~wavelet_tree() {
        delete l;
        delete r;
    }
};

// int arr[MAXN];
// wavelet_tree t;

// // arr is 1-index based
// // t.init(arr + 1, arr + n + 1, -MAXV, MAXV);

template<class T, class FUNCTION>
T upper_bound(T lo, T hi, FUNCTION&& f) {

    // last true
    T ans = -1;

    while (lo <= hi) {
        T mid = lo + (hi - lo) / 2;
        if (f(mid)) ans = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    return ans;
}

void solution() {

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    wavelet_tree t(arr);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << upper_bound(1, n, [&](int mid) {
            int x = (r - l + 1) - t.LTE(l, r, mid - 1);
            return x >= mid;
        }) << endl;
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