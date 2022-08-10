#include <bits/stdc++.h>
using namespace std;

int p[5];
int s[5];

void mkset(int n) {
    p[n] = n;
    s[n] = 1;
}

void repr(int n) {
    if (p[n] == n) return n;
    return p[n] = repr(p[n]);
}

void uni(int a, int b) {
    int ra = repr(a), rb = repr(b);
    if (ra != rb) {
        if (s[rb] > s[ra])
            swap(ra, rb);
        p[rb] = ra;
        s[ra] += s[rb];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}