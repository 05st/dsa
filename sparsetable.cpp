#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 5; // int n; cin >> n;
    int arr[n] = {4, 2, 3, 1, 5}; // int arr[n]; for (int i = 0; i < n; i++) cin >> arr[i];
    auto fn = [](int a, int b) { return min(a, b); };

    int st[n][k+1];
    int l2[n+1];
    l2[1] = 0;
    for (int i = 2; i <= n; i++)
        l2[i] = l2[i/2] + 1;
    int k = l2[n];
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];
    for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = fn(st[i][j-1], st[i + (1 << (j-1))][j-1]);

    int l = 0, r = 4;

    int q = fn(st[l][l2[r - l + 1]], st[r - (1 << l2[r - l + 1]) + 1][l2[r - l + 1]]);
//  int q = 0;
//  for (int s = 0; s < (r - l + 1); s += 1 << l2[r - l + 1 - s])
//      q = fn(q, st[l + s][l2[r - l + 1 - s]]);

    cout << q << '\n';

    return 0;
}