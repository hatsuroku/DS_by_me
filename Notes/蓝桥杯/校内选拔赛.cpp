#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#define max2(a,b) ((a) > (b) ? (a) : (b))
#define min2(a,b) ((a) < (b) ? (a) : (b))

using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    int a[100010], k[100010];
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
        k[tmp] = i;
    }
    int sign = n;
    for(int i = n; i >= 2; --i) {
        if(k[i] < k[i - 1]) {
            sign = i;
            break;
        }
    }
    cout << sign - 1 << endl;
}