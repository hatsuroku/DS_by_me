// solved by yjp
// poj 2965

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <map>
#include <list>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
//const double PI = acos(-1.0);
//const int MOD = 100000007;

typedef long long LL;
typedef unsigned long long uLL;
const int N = 10000+10;

char g[5][5];
int ans = 16;
int path[16][2];
int anspath[16][2];

inline void fr(int r, int c) {
    for (int i = 0; i < 4; ++i) {
        g[r][i] = (g[r][i] == '+' ? '-' : '+');
        g[i][c] = (g[i][c] == '+' ? '-' : '+');
    }
}

inline void flip(int r, int c) {
    if (g[r][c] == '+') {
        g[r][c] = '-';
    }
    else {
        g[r][c] = '+';
    }
    fr(r, c);
}

bool check() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (g[i][j] == '+') return false;
        }
    }
    return true;
}

void solve(int i, int d) {
    if (check()) {
        ans = min(ans, d);
        memcpy(anspath, path, sizeof(path));
    }
    if (d == ans || i == 16) return;
    int r = i / 4, c = i % 4;
    flip(r, c);
    path[d][0] = r;
    path[d][1] = c;
    solve(i + 1, d + 1);
    flip(r, c);
    solve(i + 1, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    for (int i = 0; i < 4; ++i) {
        cin >> g[i];
    }

    solve(0, 0);
    cout << ans << '\n';
    for (int i = 0; i < ans; ++i) {
        cout << anspath[i][0] + 1 << ' ' << anspath[i][1] + 1 << '\n';
    }
    return 0;
}