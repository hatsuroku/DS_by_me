/*
 * 回溯搜索
 * yjp说只要无脑暴力搜索就行了
 */

#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define max2(a,b) ((a) > (b) ? (a) : (b))
#define min2(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 110;
int n, m, res = inf;
bool rela[maxn][maxn];
int clsr[maxn][maxn];
int ccnt[maxn];


// id是学生的id，从1开始；cur是教师编号，从0开始
// 但实际上会因为初始状态所有教室都为空，0号教室不能装人，所以会从1开始装人
void solve(int id, int cur) {
    // 剪枝，如果大于已有的最小教室则不需要
    if(cur >= res) return;
    // 如果id大于已有的人数，则代表已经分配完所有人了
    if(id > n) {
        res = min2(cur, res);
        return;
    }

    // 从第一个教室开始尝试能不能装人
    for(int i = 1; i <= cur; ++i) {
        int unknown = 0;
        for(int j = 0; j < ccnt[i]; ++j) {
            if(!rela[id][clsr[i][j]]) {
                unknown++;
            }
        }
        // 教室里的人都不认识，所以可以装
        if(unknown == ccnt[i]) {
            clsr[i][ccnt[i]++] = id;
            solve(id + 1, cur);
            // 得到一个方案（不管是可行还是不可行）返回之后
            // 从这个教室里去掉自己，尝试装别的教室
            ccnt[i]--;
        }
    }
    
    // 教室里面都有认识的人，所以要开一个新教室
    clsr[cur + 1][ccnt[cur + 1]++] = id;
    solve(id + 1, cur + 1);
    ccnt[cur + 1]--;
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        rela[a][b] = rela[b][a] = true;
    }
    solve(1, 0);
    printf("%d", res);
}