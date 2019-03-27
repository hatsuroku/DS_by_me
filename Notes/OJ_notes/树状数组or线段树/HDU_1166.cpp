//HDU_1166 很普通的树状数组or线段树模板题
/* 
	导致WA的原因：
		1.读取指令的时候，无论什么情况都为%s %d %d，可是End指令没有数字，导致读多两个数据造成错乱
		2.完成一轮的时候没有初始化数据，导致下一轮继承上一轮的数据。
*/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define lowbit(k) ((k)&(-k)) 
//#define LOCAL
const int kmax = 50000 + 10;


int tree[kmax], n, t;

int sum(int k) {
	int result = 0;
	while (k) {
		result += tree[k];
		k -= lowbit(k);
	}
	return result;
}

int sum(int a, int b) {
	int result;
	if (a <= 1) {
		result = sum(b);
	}
	else {
		int big = sum(b), small = sum(a - 1);
		result = big - small;
	}
	return result;
}

void add(int k, int v) {
	while (k < kmax) {
		tree[k] += v;
		k += lowbit(k);
	}
}

int main() {
#ifdef LOCAL
	freopen("F:\\VSproject\\RealHomeWork\\CPPLearning\\CPPLearning\\input.txt", "r", stdin);
	freopen("F:\\VSproject\\RealHomeWork\\CPPLearning\\CPPLearning\\output.txt", "w", stdout);
#endif
	scanf("%d", &t);
	for (int my_case = 1; my_case <= t; ++my_case) {
		memset(tree, 0, sizeof(tree));
		scanf("%d", &n);
		printf("Case %d:\n", my_case);
		for (int i = 1; i <= n; ++i) {
			int tmp;
			scanf("%d", &tmp);
			add(i, tmp);
		}
		char ins[10];
		do {
			int k, v;
			scanf("%s", ins);
			if (!strcmp(ins, "Add")) {
				scanf("%d%d", &k, &v);
				add(k, v);
			}
			else if (!strcmp(ins, "Sub")) {
				scanf("%d%d", &k, &v);
				add(k, -v);
			}
			else if (!strcmp(ins, "Query")) {
				scanf("%d%d", &k, &v);
				int rst = sum(k, v);
				printf("%d\n", rst);
			}
			else if (!strcmp(ins, "End")) {
				break;
			}
			else {
				printf("%d", my_case);
			}
		} while (1);
	}

}