#include <bits/stdc++.h>
using namespace std;

int n;
int fw[5];
int arr[5] = {4, 2, 3, 1, 5};

void update(int i, int x) { for (int j = i; j < n; j |= j + 1) fw[j] += x; }
int query(int i) {
    int q = 0;
    for (int j = i; j >= 0; j = (j & (j + 1)) - 1) q += fw[j];
    return q;
}
int query(int l, int r) { return query(r) - query(l - 1); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n = 5; // int n; cin >> n;
    // for (int i = 0; i < n; i++) { cin >> arr[i]; fw[i] = 0; }
    for (int i = 0; i < n; i++) fw[i] = 0;
    for (int i = 0; i < n; i++) update(i, arr[i]);

    cout << query(1, 4) << '\n';
    
    return 0;
}