/*
 * 蓝桥杯 对局匹配
 * 简单的dp（虽然对我来说不简单
 */
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define max2(a,b) ((a) > (b) ? (a) : (b))
#define min2(a,b) ((a) < (b) ? (a) : (b))
#define maxscore 100005
#define maxn 100005

using namespace std;
int score_count[maxscore + 5], group_count[maxn], dp[maxn];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    int ans = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i) {
        int score;
        scanf("%d", &score);
        // score_count[score]是分数为score的人的个数
        score_count[score]++;
    }
    // 特殊处理k=0的情况
    if(k == 0) {
        for(int i = 0; i <= maxscore; ++i) {
            if(score_count[i]) ans++;
        }
    } else {
        // 分成k组，每组分别是 :
        // 0, k, 2k, ... , (m-1)k
        // 1, 1+k, 1+2k, ... ,
        // 2, 2+k, 2+2k, ... ,
        // ...
        // k-1, (k-1)+k, (k-1)+2k, ...
        // i是这些组内的分数 mod k 后的结果，根据i给分数分组
        // 每组有m个元素
        for (int i = 0; i < k; ++i) {
            int m = 0;
            for (int j = i; j <= maxscore; j += k) {
                group_count[m++] = score_count[j];
            }
            // 第一个元素选个数肯定大于等于0，所以必选
            dp[0] = score_count[0];
            for(int j = 0; j < m; ++j) {
                if(j == 1) {
                    // 第二个元素只能选择自己或第一个元素
                    dp[j] = max2(group_count[j], dp[0]);
                }
                else {
                    dp[j] = max2(group_count[j] + dp[j - 2], dp[j - 1]);
                }
            }
            // 加上这一组的最大元素
            ans += dp[m - 1];
        }
    }
    printf("%d", ans);
    return 0;
}