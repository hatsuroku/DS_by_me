#include <iostream>
#include <cstdlib>
#include <limits>
#include <queue>

#define INF 0x3f3f3f3f
#define LOCAL

using namespace std;

bool GMatrix[4000][4000];
int wall[500][500];
int d[500][500];
queue<int> q;


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m, n;
    int xmax = 0, ymax = 0;
    for(int i=2; i<500; i+=2) {
        for(int j=2; j<500; j+=2) {
            wall[i][j] = 8;
        }
    }

    for(cin >> m >> n; m>=0 && n>=0; cin >> m >> n) {
        bool isVertical;
        int x, y, length;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> isVertical >> length;
            x = 2*x-1;
            y = 2*y-1;
            if(isVertical) {
                for(int ny = y, dy = 0; dy < length; dy++) {
                    wall[x][ny] = 0;
                }
            } else {
                for(int nx = x, dx = 0; dx < length; dx++) {
                    wall[nx][y] = 0;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            cin >> x >> y >> isVertical;

            x = 2*x-1;
            y = 2*y-1;
            if(isVertical) {
                wall[x][y] = 1;
                wall[x][y+1] = 1;
                wall[x][y+2] = 1;
            } else {
                wall[x][y] = 1;
                wall[x+1][y] = 1;
                wall[x+2][y] = 1;
            }
        }

        for(int i=1; i<=7; i++) {
            for(int j=1; j<=7; j++) {
                cout << wall[i][j] << " ";
            }
            cout << "\n";
        }
    }

}

