#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#define max2(a,b) ((a) > (b) ? (a) : (b))
#define min2(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int n, k, m;
vector<int> a;

// p是官员，d是步长（1逆时针，-1顺时针），走t步
int go(int p, int d, int t) {
    while(t--) {
        do {
            // 加n-1模n再把1补回来
            // 防止n被模掉变成0
            p = (p+d+ n-1) % n + 1;
        } while(a[p] == 0);
    }
    return p;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while(cin >> n >> k >> m){
        a.clear();
        a.push_back(0);
        for(int i = 1; i <= n; ++i) {
            a.push_back(i);
        }
        int left = n;
        int p1 = n, p2 = 1;
        while(left) {
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            printf("%3d", p1);
            left--;
            if(p2 != p1) {
                printf("%3d", p2);
                left--;
            }
            a[p1] = a[p2] = 0;
            if(left) cout << ",";
        }
        cout << endl;
    }
    return 0;
}