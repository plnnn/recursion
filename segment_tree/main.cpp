#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], t[4 * N];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);

    t[v] = t[v * 2] + t[v * 2 + 1];
}

void update(int v, int l, int r, int i, int x) {
    if (l == r) {
        t[v] = a[l] = x;
        return;
    }

    int mid = (l + r) / 2;
    if (i <= mid) update(v * 2, l, mid, i, x);
    else update(v * 2 + 1, mid + 1, r, i, x);

    t[v] = t[v * 2] + t[v * 2 + 1];
}

int sum(int v, int l, int r, int lq, int rq) {
    if (l > rq || r < lq || l > r || lq > rq) return 0;
    if (lq <= l && r <= rq) return t[v];

    int mid = (l + r) / 2;
    int s1 = sum(v * 2, l, mid, lq, rq);
    int s2 = sum(v * 2 + 1, mid + 1, r, lq, rq);

    return s1 + s2;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    build(1, 1, n);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int i, x;
            cin >> i >> x;
            update(1, 1, n, i, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << sum(1, 1, n, l, r) << '\n';
        }

        /*
        cout << '\n';
        for (int i = 1; i <= n; ++i)
            cout << a[i] << ' ';
        cout << '\n';
        */
    }
    return 0;
}
