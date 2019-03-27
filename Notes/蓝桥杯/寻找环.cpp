/*
 * 无向图判环
 * 因为题目说明n个点原本构成树形网络，也就是说只有一个连通分量
 * 所以不用担心多个连通分量的问题
 * 把有向图判环的模板改一下就行了
 */


#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define max2(a,b) ((a) > (b) ? (a) : (b))
#define min2(a,b) ((a) < (b) ? (a) : (b))


using namespace std;
const int maxn = 1e5 + 2;
int n;
vector<int> adj[maxn], res;
// edgeTo[v]就是连着v的上一个点
int edgeTo[maxn];
// 是否在函数栈上
bool onStack[maxn];
// 是否已经访问过
bool marked[maxn];
bool hasCycle;

void dfs(int v) {
    onStack[v] = true;
    marked[v] = true;
    for(int i = 0; i < adj[v].size(); ++i) {
        if(hasCycle) return;
        else if(!marked[adj[v][i]]) {
            edgeTo[adj[v][i]] = v;
            dfs(adj[v][i]);
        }
        // 有向图和无向图的区别
        // 无向图要无视连着自己的上一个点，也就是edgeTo[v] != adj[v][i]这个条件
        else if(onStack[adj[v][i]] && edgeTo[v] != adj[v][i]) {
            hasCycle = true;
            for(int x = v; x != adj[v][i]; x = edgeTo[x]) {
                res.push_back(x);
            }
            res.push_back(adj[v][i]);
        }
    }
    onStack[v] = false;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}