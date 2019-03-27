// 求多个字符串的最长子序列
// 变维转一维dp

#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <random>
#define max2(a,b) ((a) > (b) ? (a) : (b))
#define min2(a,b) ((a) < (b) ? (a) : (b))

using namespace std;


char s[105][105];
int dpa[30010];
int len[110];
int n;

int dp(int *x) {
	int index, i, j, ret;
	// 如果有一个长度为0则最长子序列为0
	for(int i = 1; i <= n; ++i) {
		if (x[i] == 0) return 0;
	}
	// 多维数组[][][]映射到一维数组
	for(index = x[1] - 1, i = 2; i <= n; ++i) {
		index = index * len[i] + x[i] - 1;
	}
	// 两种映射皆可
	// for(index = x[n] - 1, i = n - 1; i >= 1; --i) {
	// 	index = index * len[i] + x[i] - 1;
	// }
	
	// 记忆化搜索
	if(dpa[index] >= 0) {
		return dpa[index];
	}

	// 比较是否最后一个字符都相等
	for(i = 2; i <= n; ++i) {
		if (s[1][x[1] - 1] != s[i][x[i] - 1]) break;
	}
	
	// 相等的情况
	if(i > n) {
		for(j = 1; j <= n; ++j) {
			x[j]--;
		}
		ret = dp(x) + 1;
		for(j = 1; j <= n; ++j) {
			x[j]++;
		}
	}
	
	// 不相等的情况
	else {
		ret = 0;
		for(j = 1; j <= n; j++) {
			x[j]--;
			int t = dp(x);
			ret = max2(t, ret);
			x[j]++;
		}
	}
	dpa[index] = ret;
	return ret;
}


// #define LOCAL
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	int temp[105];
	while(t--) {
		cin >> n;
		memset(dpa, -1, sizeof(dpa));
		for(int i = 1; i <= n; ++i) {
			scanf("%s", s[i]);
			len[i] = temp[i] = strlen(s[i]);
		}
		printf("%d\n", dp(temp));
	}
	return 0;
}