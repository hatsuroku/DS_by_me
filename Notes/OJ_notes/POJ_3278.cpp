// POJ 3278
/* 本来想着用深搜的，但是一看就觉得要炸，果不其然【。
 * 百度了一下发现是要用广搜，哎，还是我太蠢了。
 */
/* 他娘的根本没想到用INF作为分隔符居然会RE坑到自己
 * 以后不要用分隔符然后记录步数了，直接加多一个参数进去
 */

#include <iostream>
#include <cstdlib>
#include <limits>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;
bool visited[200050];

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    int count = 0;
    queue<int> q;

    cin >> n >> k;
	if(n>k) {
		cout << n-k;
		return 0;
	}
	

    q.push(n);
    q.push(INF);
    while(true) {
        n = q.front(); q.pop();
		if(n!=INF && visited[n]) continue;
		if(n!=INF)
			visited[n] = true;
        if(n == k) {
            break;
        }
        if(n == INF) {
            count++;
            q.push(INF);
			continue;
        } else {
			if(n<=50000)
				q.push(n * 2);
			if(n<100000)
				q.push(n + 1);
			if(n>0)
				q.push(n - 1);
        }

    }
    cout << count;
}

